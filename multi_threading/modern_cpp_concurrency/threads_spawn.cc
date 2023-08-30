#include <thread>
#include <chrono>
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include <functional>

void do_work(unsigned id) {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "thread " << id << " finished!" << std::endl;
}

void f() {
    std::vector<std::thread> threads;
    for (unsigned int i = 0; i < 20; i++) {
        threads.push_back(std::thread(do_work, i));
    }
    std::for_each(threads.begin(), threads.end(), std::mem_fn(&std::thread::join));
}

int main(int argc, char *argv[])
{
    f();
    return 0;
}

