#include <condition_variable>
#include <mutex>
#include <chrono>
#include <thread>
#include <iostream>

class EventBuffer {
public:
    EventBuffer() {}

    void set_event() {
        std::unique_lock<std::mutex> lock(mutex);
        event = true;
        cv.notify_one();
    }

    void wait_event() {
        std::unique_lock<std::mutex> lock(mutex);
        while (!event)
        {
            cv.wait(lock);
        }
        event = false;
    }
private:
    std::condition_variable cv;
    std::mutex mutex;
    bool event = false;
};

auto buffer = EventBuffer();

void thread1_func() {
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout << "I will send signal to another thread!" << std::endl;
    buffer.set_event();
}

void thread2_func() {
    buffer.wait_event();
    std::cout << "Some signals send to me!" << std::endl;
}

int main() {
    std::thread th1(thread1_func);
    std::thread th2(thread2_func);
    th1.join();
    th2.join();
    return 0;
}