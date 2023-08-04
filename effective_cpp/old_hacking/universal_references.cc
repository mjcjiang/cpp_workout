#include <iostream>
#include <vector>
#include <type_traits>

// Function template to check if a universal reference is an lvalue or rvalue
template <typename T>
void checkReference(T&& arg) {
    // Use std::is_lvalue_reference and std::is_rvalue_reference to check the reference type
    if (std::is_lvalue_reference<decltype(arg)>::value) {
        std::cout << "Universal reference is an lvalue reference." << std::endl;
    } else if (std::is_rvalue_reference<decltype(arg)>::value) {
        std::cout << "Universal reference is an rvalue reference." << std::endl;
    } else {
        std::cout << "Reference type cannot be determined." << std::endl;
    }
}

template <typename T>
void f(std::vector<T>&& param) {
    for (auto &e : param) {
        std::cout << e << std::endl;
    }
}

void test(int param) {
    std::cout << param << std::endl;
}

auto timeFuncInvocation = [](auto&& func, auto&&... params) {
    std::forward<decltype(func)>(func)(std::forward<decltype(params)>(params)...);
};

int main() {
    int x = 42;
    // Universal reference with an lvalue argument
    checkReference(x); // Output: Universal reference is an lvalue reference.
    // Universal reference with an rvalue argument
    checkReference(123); // Output: Universal reference is an rvalue reference.
    
    std::vector<int> i_vec = {1, 2, 3, 4};
    f(std::move(i_vec));

    for (auto &e : i_vec) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    timeFuncInvocation(test, 1);
    return 0;
}
