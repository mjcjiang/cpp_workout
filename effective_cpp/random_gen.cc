#include <iostream>
#include <chrono>
#include <random>
#include <thread>

template <typename T> 
class UniIntRandomGen {
public:
    UniIntRandomGen(T begin, T end) {
        _begin = begin;
        _end = end;
        seed = rd() ^ (get_current_stamp<std::chrono::seconds>() + get_current_stamp<std::chrono::microseconds>());
        _gen = std::mt19937(seed);
        _distrib = std::uniform_int_distribution(_begin, _end);
    }

    T get_random_num() {
        return _distrib(_gen);
    }
private:
    template<typename U>
    std::mt19937::result_type get_current_stamp() {
        auto stamp = std::chrono::duration_cast<U>(std::chrono::high_resolution_clock::now().time_since_epoch()).count();
        return static_cast<std::mt19937::result_type>(stamp);
    }
private:
    T _begin;
    T _end;
    std::random_device rd;          
    std::mt19937::result_type seed;
    std::mt19937 _gen;
    std::uniform_int_distribution<T> _distrib;
};

int main() {
    auto random_gen = UniIntRandomGen<unsigned>(1, 200);
    for(int i = 0; i < 10; i++) {
        std::cout << random_gen.get_random_num() << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    return 0;
}
