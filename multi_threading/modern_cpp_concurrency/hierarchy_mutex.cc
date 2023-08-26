#include <mutex>
#include <thread>
#include <chrono>
#include <climits>
#include <iostream>

class hierarch_mutex {
public:
    explicit hierarch_mutex(unsigned long val)
        : hierarch_val(val), prev_hierach_val(0) {}

    void lock() {
        check_for_hierarch_violation();
        mutex_.lock();
        update_hierarch_value();
    }

    void unlock() {
        this_thread_hierarch_val = prev_hierach_val;
        mutex_.unlock();
    }

    bool try_lock() {
        check_for_hierarch_violation();
        if(!mutex_.try_lock())
            return false;
        update_hierarch_value();
        return true;
    }
private:
    void check_for_hierarch_violation() {
        if (this_thread_hierarch_val <= hierarch_val) {
            throw std::logic_error("mutex hierarch violated");
        }
    }

    void update_hierarch_value() {
        prev_hierach_val = this_thread_hierarch_val;
        this_thread_hierarch_val = hierarch_val;
    }
private:
    std::mutex mutex_;
    unsigned long const hierarch_val;
    unsigned long prev_hierach_val;
    static thread_local unsigned long this_thread_hierarch_val;
};

thread_local unsigned long hierarch_mutex::this_thread_hierarch_val(ULONG_MAX);

hierarch_mutex high_level_mutex(10000);
hierarch_mutex low_level_mutex(5000);
hierarch_mutex other_level_mutex(100);

int do_low_level_staff() {
    std::this_thread::sleep_for(std::chrono::seconds(10));
    std::cout << "low staff finished..." << std::endl;
    return 10;
}

int low_level_func() {
    std::lock_guard<hierarch_mutex> lk(low_level_mutex);
    return do_low_level_staff();
}

void do_high_level_staff(int some_param) {
    std::this_thread::sleep_for(std::chrono::seconds(10));
    std::cout << "high staff finished..." << std::endl;
}

void high_level_func() {
    std::lock_guard<hierarch_mutex> lk(high_level_mutex);
    do_high_level_staff(low_level_func());
}

void do_other_staff() {
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "other staff finished..." << std::endl;
}

void other_staff_func() {
    std::lock_guard<hierarch_mutex> lk(other_level_mutex);
    high_level_func();
    do_other_staff();
}

void thread_a() {
    high_level_func();
}

void thread_b() {
    high_level_func();
}

void thread_c() {
    other_staff_func();
}

int main(int argc, char *argv[])
{
    std::thread a(thread_a);
    std::thread b(thread_b);
    std::thread c(thread_c);
    a.join();
    b.join();
    c.join();
    return 0;
}
