#include <thread>
#include <future>
#include <iostream>
#include <functional>
#include <cstdint>
#include <chrono>
#include <string>
#include <vector>

uint64_t cal_one_segs(uint64_t start, uint64_t end) {
    uint64_t res = 0;
    for (uint64_t i = start; i <= end; i++) {
        res += i;
    }
    return res;
}

using task_func = uint64_t();

uint64_t concurrent_cal(uint64_t start, uint64_t end, uint64_t task_num) {
    uint64_t result = 0;
    uint64_t segs_length = (end - start + 1) / task_num;
    uint64_t segs_remain = (end - start + 1) % task_num;

    std::vector<std::packaged_task<task_func>> task_vector;
    std::vector<std::future<uint64_t>> future_vector;

    //task schedule
    for (int i = 0; i < task_num; i++) {
        uint64_t cur_start = start + i * segs_length;
        uint64_t cur_end = cur_start + segs_length - 1;
        task_vector.emplace_back(std::packaged_task<task_func>(std::bind(cal_one_segs, cur_start, cur_end)));
        future_vector.emplace_back(task_vector.back().get_future());
    }

    if (segs_remain) {
        uint64_t cur_start = start + task_num * segs_length;
        uint64_t cur_end = cur_start + segs_remain;
        task_vector.emplace_back(std::packaged_task<task_func>(std::bind(cal_one_segs, cur_start, cur_end)));
        future_vector.emplace_back(task_vector.back().get_future());
    }

    //run task
    for (auto &task : task_vector) {
        std::thread(std::move(task)).detach();
    }

    //reduce result
    for (auto &fu : future_vector) {
        result += fu.get();
    }

    return result;
}

template <typename Functor>
void log_running_time(Functor func, const std::string& name) {
    auto start = std::chrono::high_resolution_clock::now();
    func();
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    std::cout << "Running time of " << name << ": " << duration.count() << " nanoseconds" << std::endl;
}

int main(int argc, char *argv[])
{
    /*
    std::cout << concurrent_cal(1, 100000000, 10) << std::endl;
    std::cout << cal_one_segs(1, 100000000) << std::endl;
    */
    //log_running_time([] {int i = 0; i++;}, "test");
    log_running_time(std::bind(concurrent_cal, 1, 1000000000, 10), "concurrent_cal");
    log_running_time(std::bind(cal_one_segs, 1, 1000000000), "cal_one_segs");
    return 0;
}
