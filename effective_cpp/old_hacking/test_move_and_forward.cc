/*
 * Item 23: Understand std::move and std::forward
 */

#include <iostream>
#include <memory>
#include <typeinfo>
#include <type_traits>
#include <chrono>

class Test {
public:
    Test(int n) : num(n) {}
    ~Test() {}

    //copy constructor
    Test(const Test &other) : num(other.num) {
        std::cout << "This is the copy constructor" << std::endl;
    }

    //copy assignment constructor
    Test &operator=(const Test& other) {
        std::cout << "This is the copy assignment constructor" << std::endl;
        if (this != &other) {
            num = other.num;
        }
        return *this;
    }

    //move constructor
    Test(Test &&other) noexcept : num(std::move(other.num)) {
        std::cout << "This is the move constructor" << std::endl;
    }

    //move assginment constructor
    Test &operator=(Test &&other) noexcept {
        std::cout << "This is the move assignment constructor" << std::endl;
        if (this != &other) {
            num = std::move(other.num);
        }
        return *this;
    }

  private:
    int num;
};

template<typename T>
void tell_ref_type(T &&reference) {
    if (std::is_lvalue_reference<T>::value) {
        std::cout << "Reference is a lvalue reference." << std::endl;
    } else {
        std::cout << "Reference is an rvalue reference." << std::endl;
    }
}

void processTest(const Test &lvalue) {
    std::cout << "process lvalue Test" << std::endl;
}

void processTest(Test &&rvalue) {
    std::cout << "process rvalue Test" << std::endl;
}

template <typename T>
void logAndProcess(T &&param) {
    auto now = std::chrono::system_clock::now().time_since_epoch().count();
    std::cout << "Calling process..." << now << std::endl;
    processTest(std::forward<T>(param));
}

int main() {
    /*
    const Test test1(1);
    Test test2(std::move(test1));

    Test test3(3);
    Test test4(std::move(test3));

    std::cout << typeid(std::move(test3)).name() << std::endl;
    int x = 10;
    tell_ref_type(x);
    */
    Test test(1);
    logAndProcess(test);
    logAndProcess(std::move(test));
}
