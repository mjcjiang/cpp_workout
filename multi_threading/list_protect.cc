#include <list>
#include <mutex>
#include <algorithm>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <random>

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
private:
    std::list<LogRecord> record_list_;
    std::mutex list_mutex_;
};

int main(int argc, char *argv[])
{
    return 0;
}
