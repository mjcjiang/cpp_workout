#include <algorithm>
#include <iostream>
#include <array>

int main(int argc, char *argv[])
{
    int a = 1, b = 2;
    std::swap(a, b);
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;

    auto print = [](const int &n) {std::cout << ' ' << n;};

    std::array<int, 3> arr1 {1,2,3};
    std::array<int, 3> arr2 {4,3,2};
    std::cout << "Before swap: \n";
    std::for_each(arr1.begin(), arr1.end(), print);
    std::for_each(arr2.begin(), arr2.end(), print);
    std::swap(arr1, arr2);
    std::cout << "After swap: \n";
    std::for_each(arr1.begin(), arr1.end(), print);
    std::for_each(arr2.begin(), arr2.end(), print);
    return 0;
}

