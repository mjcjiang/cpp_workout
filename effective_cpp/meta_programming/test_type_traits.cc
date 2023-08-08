#include <iostream>
#include <type_traits>

struct A {
    int a;
    int f(int) {return 2023;}
};

enum E {
    e = 1,
};

union U {
    int u;
};

int main() {
    std::cout << std::boolalpha << std::endl;
    std::cout << std::is_void<void>::value << std::endl;
    std::cout << std::is_integral<short>::value << std::endl;
    std::cout << std::is_floating_point<double>::value << std::endl;
    std::string a = "This is string a";
    std::string b = "This is string b";
    std::cout << std::is_same<decltype(a), decltype(b)>::value << std::endl;
    return 0;
}
