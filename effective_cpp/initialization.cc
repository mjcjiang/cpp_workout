#include <iostream>
#include <vector>
#include <atomic>
#include <string>
#include <vector>
#include <thread>

class Widget {
public:
    Widget() {
        std::cout << "In default Widget()" << std::endl;
    }

    Widget(int i, bool b) {
        std::cout << "In Widget(int i, bool b)" << std::endl;
    }

    Widget(int i, double d) {
        std::cout << "In Widget(int i, double d)" << std::endl;
    }
    /*
    Widget(std::initializer_list<long double> il) {
        std::cout << "In Widget(std::initializer_list<long double> il)" << std::endl;
    }
    */
    Widget(std::initializer_list<std::string> bl) {
        std::cout << "In Widget(std::initializer_list<bool> il)" << std::endl;
    }
private:
    int number;
    bool is_new;
    double price;
};

int main() {
    /*
    std::vector<int> v{1,2,4};
    for (const auto& e: v) {
        std::cout << e << std::endl;
    }

    std::atomic<int> at1{0};
    std::atomic<int> at2(1);
    //std::atomic<int> at3 = 0;

    //{} can prohibit "narrowing conversions"?
    double x, y, z;
    x = y = z = 1.0;
    
    int sum1{x + y + z};
    */

    //Widget w1{10, true};
    //Widget w2{10, 3.3};
    std::vector<int> v1(10, 20);
    for (const auto& e: v1) {
        std::cout << e << " ";
    }
    std::cout << std::endl;


    std::vector<int> v2{10, 20};
    for (const auto& e: v2) {
        std::cout << e << " ";
    }
    std::cout << std::endl;
    std::cout << "This is a test line" << std::endl;
    return 0;
}
