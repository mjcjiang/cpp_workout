#include <thread>
#include <iostream>

class Widget {
public:
    Widget() : counter(0) {}
    void update_counter() { counter++; }
    int get_counter() { return counter; }
private:
    int counter;
};

void update_counter_of_widget(Widget &widget) {
    widget.update_counter();
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

struct func {
    int& i;
    func(int &i_) : i(i_) {}
    void operator()() {
        for (unsigned j = 0; j < 1000000; j++) {
            i++;
        }
    }
};

class scoped_thread {
public:
    explicit scoped_thread(std::thread t_) : t(std::move(t_)) {
        if(!t.joinable())
            throw std::logic_error("No thread");
    }

    ~scoped_thread() {
        t.join();
    }

    scoped_thread(scoped_thread const &) = delete;
    scoped_thread& operator=(scoped_thread const&) = delete;
  private:
    std::thread t;
};

int main(int argc, char *argv[])
{
    /*
    Widget widget;
    widget.update_counter();
    
    std::cout << "first update, counter is: " << widget.get_counter()
              << std::endl;
    std::thread t(update_counter_of_widget, std::ref(widget));
    t.join();

    std::cout << "thread update, counter is: " << widget.get_counter()
              << std::endl;
    */
    int some_local_counter = 0;
    {
        scoped_thread t(std::thread(func{some_local_counter}));
    }
    std::cout << "Now the local counter is: " << some_local_counter << std::endl;
    return 0;
}
