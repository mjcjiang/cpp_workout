#include <iostream>
#include <thread>
#include <chrono>

void thread_func1() {
    for (int i = 0; i < 100; i++) {
        std::cout << "This is thread_func1 with tid: " << std::this_thread::get_id() << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void thread_func2() {
    for (int i = 0; i < 100; i++) {
        std::cout << "This is thread_func2 with tid: " << std::this_thread::get_id() << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

int main(int argc, char *argv[])
{
    std::thread t1(thread_func1);
    std::thread t2(thread_func2);
    t1.join();
    t2.join();
    return 0;
}

