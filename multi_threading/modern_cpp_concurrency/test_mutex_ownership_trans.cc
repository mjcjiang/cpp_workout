#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

std::mutex mu;

std::unique_lock<std::mutex> get_lock() {
    std::unique_lock<std::mutex> lk(mu);
    std::cout << "In get_lock, wait some seconds...";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    return lk;
}

void process_data(const std::string& thread_name) {
    std::unique_lock<std::mutex> lk(get_lock());
    std::cout << thread_name << " in process data, do some data processing..." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

int main(int argc, char *argv[])
{
    std::thread first_thread(process_data, "first_thread");
    std::thread second_thread(process_data, "second_thread");
    first_thread.join();
    second_thread.join();
    return 0;
}

