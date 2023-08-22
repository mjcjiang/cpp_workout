#include <mutex>
#include <thread>
#include <climits>

class hierarch_mutex {
public:
    explicit hierarch_mutex(unsigned long val)
        : hierarch_val(val), prev_hierach_val(0) {}
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
