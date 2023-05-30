#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <forward_list>
#include <tuple>

void test_vector() {
    std::vector<int> v;
    std::cout << "size:" << v.size() << std::endl;         // output 0
    std::cout << "capacity:" << v.capacity() << std::endl; // output 0

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    std::cout << "size:" << v.size() << std::endl;         // output 3
    std::cout << "capacity:" << v.capacity() << std::endl; // output 4

    v.push_back(4);
    v.push_back(5);
    std::cout << "size:" << v.size() << std::endl;         // output 5
    std::cout << "capacity:" << v.capacity() << std::endl; // output 8

    v.clear();
    std::cout << "size:" << v.size() << std::endl;         // output 0
    std::cout << "capacity:" << v.capacity() << std::endl; // output 8

    v.shrink_to_fit();
    std::cout << "size:" << v.size() << std::endl;         // output 0
    std::cout << "capacity:" << v.capacity() << std::endl; // output 0
}

void foo(int *p, int len) {
    std::cout << "--------in function foo--------------" << std::endl;
    for(int i = 0; i < len; i++) {
        std::cout << *(p+i) << std::endl;
    }
}

void test_array() {
    std::array<int, 4> arr = {1, 3, 2, 4};
    if (arr.empty()) {
        std::cout << "The array is empty!" << std::endl;
    } else {
        std::cout << "The array is not empty!" << std::endl;
    }

    std::cout << "The size of array: " << arr.size() << std::endl;

    for(auto &i: arr) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    //use lambda for sort
    std::sort(arr.begin(), arr.end(), [](int a, int b) {
        return a < b;
    });
    for(auto &i: arr) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    //int *arr_p = arr;
    foo(arr.data(), arr.size());
    foo(&arr[0], arr.size());
}

void test_forward_list() {
    std::forward_list<int> lst = {1,3,2,4};
    lst.push_front(5);

    for(auto &e : lst) {
        std::cout << e << " ";
    }
    std::cout << std::endl;
}

void test_map_and_unordered_map() {
    // initialized in same order
    std::unordered_map<int, std::string> u = {
        {1, "1"},
        {3, "3"},
        {2, "2"}
    };
    std::map<int, std::string> v = {
        {1, "1"},
        {3, "3"},
        {2, "2"}
    };

    // iterates in the same way
    std::cout << "std::unordered_map" << std::endl;
    for( const auto & n : u)
        std::cout << "Key:[" << n.first << "] Value:[" << n.second << "]\n";

    std::cout << std::endl;
    std::cout << "std::map" << std::endl;
    for( const auto & n : v)
        std::cout << "Key:[" << n.first << "] Value:[" << n.second << "]\n";
}

auto get_student(int id) {
    if (id == 0)
        return std::make_tuple(3.8, 'A', "John");
    if (id == 1)
        return std::make_tuple(2.9, 'C', "Jack");
    if (id == 2)
        return std::make_tuple(1.7, 'D', "Ive");

    // it is not allowed to return 0 directly
    // return type is std::tuple<double, char, std::string>
    return std::make_tuple(0.0, 'D', "null");
}

void test_tuples() {
    auto student = get_student(0);
    std::cout << "ID: 0, "
              << "GPA: "   << std::get<0>(student) << ", "
              << "Grade: " << std::get<1>(student) << ", "
              << "Name: "  << std::get<2>(student) << '\n';

    double gpa;
    char grade;
    std::string name;

    // unpack tuples
    std::tie(gpa, grade, name) = get_student(1);
    std::cout << "ID: 1, "
              << "GPA: "   << gpa << ", "
              << "Grade: " << grade << ", "
              << "Name: "  << name << '\n';
}

int main() {
    test_vector();
    test_array();
    test_forward_list();
    test_map_and_unordered_map();
    test_tuples();
}