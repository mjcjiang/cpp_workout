#include <atomic>
#include <thread>
#include <string>
#include <iostream>

std::string work;
std::atomic<bool> ready(false);

void consumer() {
    while(!ready.load());
    std::cout << work << std::endl;
}

void producer() {
    work = "Done!";
    ready.store(true);
}

int main() {
    std::thread prod(producer);
    std::thread con(consumer);
    prod.join();
    con.join();
    return 0;
}
