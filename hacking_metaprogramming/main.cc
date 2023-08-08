#include <iostream>
#include <type_traits>

template <int N> struct Factorial {
    static int const value = N * Factorial<N-1>::value;
};

template <>
struct Factorial<1> {
    static int const value = 1;
};

template <typename T>
struct removeConst {
    using type = T;
};

template <typename T>
struct removeConst<const T> {
    using type = T;
};

int main() {
    std::cout << std::boolalpha;
    std::cout << std::is_same<int, removeConst<int>::type>::value << std::endl;
    std::cout << std::is_same<int, removeConst<const int>::type>::value << std::endl;
    // std::cout << "Factorial<5>::value: " << Factorial<5>::value << "\n";
    // std::cout << "Factorial<10>::value: " << Factorial<10>::value << "\n";
  return 0;
}
