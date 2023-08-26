#include <iostream>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <thread>
#include <chrono>
#include <sstream>
#include <string>

struct Message {
    std::string msg;
    bool is_last;
};

std::mutex mut;
std::condition_variable cond;
std::queue<Message> msg_queue;

void producer_thread_func() {
    int i = 0;
    while (i < 10) {
        std::lock_guard<std::mutex> lk(mut);
        std::stringstream ss;
        Message msg = { "hello", false };
        msg_queue.push(msg);
        cond.notify_one();
        i++;
    }

    std::lock_guard<std::mutex> lk(mut);
    Message msg = { "This is the last message", true };
    msg_queue.push(msg);
    cond.notify_one();
}

void consumer_thread_func() {
    while (1) {
        std::unique_lock<std::mutex> lk(mut);
        cond.wait(lk, [] { return !msg_queue.empty(); });
        auto msg = msg_queue.front();
        std::cout << "In consumer thread..." << std::endl;
        std::cout << msg.msg << std::endl;
        msg_queue.pop();
        lk.unlock();

        if (msg.is_last)
            break;
    }
}

int main(int argc, char *argv[])
{
    std::thread pr1(producer_thread_func);
    std::thread cu1(consumer_thread_func);
    pr1.join();
    cu1.join();
    return 0;
}

