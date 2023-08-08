#include <iostream>

int power(int m, int n) {
    int r = 1;
    for (int k = 1; k <= n; k++) 
        r = r * m;
    return r;
}

template <int m, int n> struct Power {
    static int const value = m * Power<m, n-1>::value;
};

template <int m> struct Power<m, 0> {
    static int const value = 1;
};

template <int n> int NewPower(int m) {
    return m * NewPower<n-1>(m);
}

template <> int NewPower<0>(int m) {
    return 1;
}

int main() {
    std::cout << "power(2, 10)= " << power(2, 10) << std::endl;
    std::cout << "Power<2, 10>::value= " << Power<2, 10>::value << std::endl;

    std::cout << "NewPower<0>(10)= " << NewPower<0>(10) << std::endl;
    std::cout << "NewPower<1>(10)= " << NewPower<1>(10) << std::endl;
    std::cout << "NewPower<2>(10)= " << NewPower<2>(10) << std::endl;
}
