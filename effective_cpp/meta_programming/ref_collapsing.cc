#include <iostream>
#include <string>
#include <type_traits>

template<typename T>
void func(T&& param) {
    std::cout << typeid(param).name() << std::endl;
}

int main() {
    std::string a = "this is a string";
    func(a);
    func("This is a string a");

    int x = 10;
    return 0;
}
