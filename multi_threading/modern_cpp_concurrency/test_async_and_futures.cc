#include <iostream>
#include <future>
#include <thread>
#include <chrono>

int some_big_heavy_cal() {
    std::cout << "big heavy call start..." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(10));
    std::cout << "big heavy call finish..." << std::endl;
    return 1024;
}

int main(int argc, char *argv[])
{
    std::future<int> ans = std::async(some_big_heavy_cal);
    std::cout << "In main, do something else start..." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout << "In main, do something else finish..." << std::endl;
    std::cout << "Big result: " << ans.get() << std::endl;
    return 0;
}

