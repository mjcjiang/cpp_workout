#include <thread>
#include <algorithm>
#include <numeric>
#include <vector>
#include <functional>
#include <iostream>

template <typename Iterator, typename T>
struct accumulate_block {
    void operator()(Iterator first, Iterator last, T &result) {
        result = std::accumulate(first, last, result);
    }
};

template <typename Iterator, typename T>
T parallel_accumulate(Iterator first, Iterator last, T init) {
    unsigned long const length = std::distance(first, last);
    if (!length)
        return init;

    unsigned long const min_per_threads = 25;
    unsigned long const max_threads = (length + min_per_threads - 1) / min_per_threads;
    unsigned long const hardware_threads = std::thread::hardware_concurrency();
    unsigned long const num_threads = std::min(hardware_threads!=0?hardware_threads:2, max_threads);
    unsigned long const block_size = length/num_threads;

    std::cout << "Some running message: " << std::endl;
    std::cout << "min_per_threads: " << min_per_threads << std::endl;
    std::cout << "hardware_threads: " << hardware_threads << std::endl;
    std::cout << "num_threads: " << num_threads << std::endl;
    std::cout << "block_size: " << block_size << std::endl;

    std::vector<T> results(num_threads);
    std::vector<std::thread> threads(num_threads - 1);

    Iterator block_start=first;
    for (unsigned long i = 0; i < (num_threads - 1); ++i) {
        Iterator block_end = block_start;
        std::advance(block_end, block_size);
        threads[i] = std::thread(accumulate_block<Iterator, T>(),
                                 block_start,
                                 block_end,
                                 std::ref(results[i]));
        block_start = block_end;
    }

    accumulate_block<Iterator, T>() (
                                     block_start,
                                     last,
                                     results[num_threads - 1]
                                     );

    std::for_each(threads.begin(), threads.end(), std::mem_fn(&std::thread::join));
    return std::accumulate(results.begin(), results.end(), init);
}

int main(int argc, char *argv[])
{
    std::vector<int> resources;
    for (int i = 0; i < 100000; i++) {
        resources.push_back(i+1);
    }

    int init = 0;
    int res = parallel_accumulate(resources.begin(), resources.end(), init);
    std::cout << "result is: " << res << std::endl;
    return 0;
}
