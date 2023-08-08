#include <iostream>

template <int M, int N>
struct Average {
    constexpr static int value = Average<(M + N) / 2, 0>::value;
};

template <int M>
struct Average<M, 0> {
    constexpr static int value = M; 
};

constexpr double average(double a, double b) {
    return (a + b) / 2;
}

int main() {
    std::cout << Average<100, 120>::value << std::endl;
    constexpr double res = average(100.0, 120.0);
    std::cout << res << std::endl;
    return 0;
}
