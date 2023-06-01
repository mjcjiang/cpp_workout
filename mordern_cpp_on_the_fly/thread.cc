#include <iostream>
#include <thread>
#include <mutex>
#include <future>
#include <chrono>
#include <string>
#include <queue>
#include <atomic>
#include <condition_variable>

int v;

void critical_section(int change_v) {
    static std::mutex mtx;
    std::lock_guard<std::mutex> lock(mtx);

    v = change_v;
}

void unique_critical_section(int change_v, const std::string &route_name) {
    std::cout << "route_name: " << route_name << std::endl;
    static std::mutex mtx;
    std::unique_lock<std::mutex> lock(mtx);

    v = change_v;
    std::cout << v << std::endl;
    lock.unlock();

    std::chrono::seconds duration(1);
    std::this_thread::sleep_for(duration);

    lock.lock();
    v += 1;
    std::cout << v << std::endl;
}

void test_future() {
    std::packaged_task<int()> task([](){return 7;});
    std::future<int> result = task.get_future(); //run task in a thread
    std::thread(std::move(task)).detach();
    std::cout << "Waiting...";
    //sleep 2 seconds just minic do something
    std::this_thread::sleep_for(std::chrono::seconds(2));
    result.wait();
    //done
    std::cout << "Done!" << std::endl;
    std::cout << "future result is: " << result.get() << std::endl;
}

void test_conditional_var() {
    std::queue<int> produced_nums;
    std::mutex mtx;
    std::condition_variable cv;
    bool notified = false;  // notification sign

    auto producer = [&]() {
        for (int i = 0; ; i++) {
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            std::unique_lock<std::mutex> lock(mtx);
            std::cout << "producing " << i << std::endl;
            produced_nums.push(i);
            notified = true;
            cv.notify_all();
        }
    };

    auto consumer = [&]() {
        while (true) {
            std::unique_lock<std::mutex> lock(mtx);
            while (!notified) {  // avoid spurious wakeup
                cv.wait(lock);
            }

            // temporal unlock to allow producer produces more rather than
            // let consumer hold the lock until its consumed.
            lock.unlock();
            // consumer is slower
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            lock.lock();
            if (!produced_nums.empty()) {
                std::cout << "consuming " << produced_nums.front() << std::endl;
                produced_nums.pop();
            }
            notified = false;
        }
    };

    std::thread p(producer);
    std::thread cs[2];
    for (int i = 0; i < 2; ++i) {
        cs[i] = std::thread(consumer);
    }
    p.join();
    for (int i = 0; i < 2; ++i) {
        cs[i].join();
    }
}

void test_atomic_operation() {
    int a = 0;
    volatile int flag = 0;

    std::thread t1([&]() {
        while (flag != 1);

        int b = a;
        std::cout << "b = " << b << std::endl;
    });

    std::thread t2([&]() {
        a = 5;
        flag = 1;
    });

    t1.join();
    t2.join();
}

void test_atomic_operation_new() {
    std::atomic<int> count = {0};

    std::thread t1([&](){
        count.fetch_add(1);
    });
    
    std::thread t2([&](){
        count++;        // identical to fetch_add
        count += 1;     // identical to fetch_add
    });

    t1.join();
    t2.join();
    std::cout << count << std::endl;
}

struct A {
    float x;
    int y;
    long long z;
};

void test_lock_free() {
    std::cout << sizeof(A) << std::endl;
    std::atomic<A> a;
    std::cout << std::boolalpha << a.is_lock_free() << std::endl;
    std::atomic<int> b;
    std::cout << std::boolalpha << b.is_lock_free() << std::endl;
}

int main() {
    test_lock_free();
    //test_atomic_operation_new();
    //test_future();
    //test_conditional_var();
    //test_atomic_operation();
    /*
    std::thread t1(unique_critical_section, 2, "t1"), t2(unique_critical_section, 3, "t2");
    t1.join();
    t2.join();

    std::cout << "Now v is: " << v << std::endl;
    */
    return 0;
}