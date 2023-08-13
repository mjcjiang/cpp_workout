#include <iostream>

int main() {
    int x = 10;
    auto c1 = [x](int y) {return x * y > 35;};
    auto c2 = c1;
    auto c3 = c2;
    std::cout << typeid(c1).name() << std::endl;
    return 0;
}
