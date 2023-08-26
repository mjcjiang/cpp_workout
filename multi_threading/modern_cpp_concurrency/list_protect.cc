#include <list>
#include <mutex>
#include <algorithm>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <random>
#include <thread>

using namespace std::chrono;

std::string get_system_timestamp() {
    auto now = system_clock::now();
    std::time_t time = system_clock::to_time_t(now);
    std::tm* local_time = std::localtime(&time);

    std::ostringstream oss;
    oss << std::put_time(local_time, "%Y%m%d %H%M%S")
        << "." << duration_cast<microseconds>(now.time_since_epoch()).count() % 1000000;
    std::string res = oss.str();
    return res;
}

int gen_random(int start, int end) {
    std::random_device rd;
    std::mt19937 generator(rd());

    std::uniform_int_distribution<int> distribution(1, 100);
    return distribution(generator);
}

class LogRecord {
public:
    LogRecord(const std::string &thread_name) : thread_name_(thread_name) {
        stamp_ = get_system_timestamp();
        value_ = gen_random(1, 100);
    }

    void show_record() {
        std::cout << "stamp: " << stamp_ << std::endl;
        std::cout << "value: " << value_ << std::endl;
        std::cout << "thread_name: " << thread_name_ << std::endl;
    }
  private:
    std::string stamp_;
    int value_;
    std::string thread_name_;
};

class RecordList {
public:
    void add_to_list(const std::string &thread_name) {
        std::lock_guard<std::mutex> guard(list_mutex_);
        record_list_.push_back(LogRecord(thread_name));
    }

    void show_list() {
        std::lock_guard<std::mutex> guard(list_mutex_);
        std::cout << "--------------------------------" << std::endl;
        for (auto &e : record_list_) {
            e.show_record();
        }
        std::cout << "--------------------------------" << std::endl;
    }
  private:
    std::list<LogRecord> record_list_;
    std::mutex list_mutex_;
};

void add_to_list(RecordList& lst, const std::string &thread_name) {
    for (int i = 0; i < 10; ++i) {
        lst.add_to_list(thread_name);
        std::this_thread::sleep_for(seconds(1));
    }
}

void tell_list(RecordList &lst) {
    for (int i = 0; i < 5; ++i) {
        lst.show_list();
        std::this_thread::sleep_for(seconds(3));
    }
}

int main(int argc, char *argv[])
{
    RecordList records;
    std::thread write_thread1(add_to_list, std::ref(records), "write_thread1");
    std::thread write_thread2(add_to_list, std::ref(records), "write_thread2");
    std::thread tell_thread(tell_list, std::ref(records));

    write_thread1.join();
    write_thread2.join();
    tell_thread.join();
    return 0;
}
