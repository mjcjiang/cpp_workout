#include <iostream>
#include <thread>
#include <atomic>
#include <chrono>
#include <mutex>

class MySpinLock {
public:
    MySpinLock() : flag(ATOMIC_FLAG_INIT) {}
    void lock() {
        while(flag.test_and_set());
    }

    void unlock() {
        flag.clear();
    }
  private:
    std::atomic_flag flag;
};

MySpinLock spin;
std::mutex mut;

void workOnResource() {
    mut.lock();
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    mut.unlock();
}

int main() {
    std::thread t1(workOnResource);
    std::thread t2(workOnResource);
    t1.join();
    t2.join();
    return 0;
}
