#include <iostream>
#include <thread>
#include <chrono>

class background_task {
public:
    void operator()() const {
        std::cout << "This is a background task" << std::endl;
    }
};

struct func {
    int& i;
    func(int &i_) : i(i_) {}
    void operator()() {
        for (unsigned j = 0; j < 1000000; j++) {
            i++;
        }
    }
};

void oops() {
    int local_var = 0;
    func my_func(local_var);
    std::thread my_thread(my_func);
    my_thread.detach();
}

class thread_guard {
public:
    explicit thread_guard(std::thread &t_) : t(t_) {}
    ~thread_guard() {
        if (t.joinable())
            t.join();
    }
    thread_guard(thread_guard const&) = delete;
    thread_guard& operator=(thread_guard const&) = delete;
  private:
    std::thread& t;
};

void f() {
    int some_local_var = 0;
    func my_func(some_local_var);
    std::thread t(my_func);
    thread_guard g(t);

    std::cout << "In function f, do something simple..." << std::endl;
}

void independentThread() {
    std::cout << "Start independent Thread" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "Leave independent Thread" << std::endl;
}

void threadCaller() {
    std::cout << "Start thread caller....\n";
    std::thread t(independentThread);
    t.detach();
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout << "Leave thread caller....\n";
}

int main(int argc, char *argv[])
{
    threadCaller();
    return 0;
}
