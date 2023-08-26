#include <thread>
#include <future>
#include <iostream>
#include <queue>

long long int cal_one_segs(long long int start, long long int end) {
    long long int res = 0;
    for (long long int i = start; i <= end; i++) {
        res += i;
    }
    return res;
}

using task_func = long long int(long long int, long long int);

int main(int argc, char *argv[])
{
    long long int start = 1L;
    long long int end = 100000L;
    long long int segs_num = 10;
    long long int segs_length = (end - start + 1) / segs_num;
    long long int segs_remain = (end - start + 1) % segs_num;

    std::queue<std::packaged_task<task_func>> task_queue;
    return 0;
}
