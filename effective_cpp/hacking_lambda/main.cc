/*
* Author: hjiang
* Created: 2023-08-09
*
* This is a comment describing the purpose of the code.
* Additional comments can be added here.
*/

#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

using FilterContainer = std::vector<std::function<bool(int)>>;
FilterContainer filters;

void addDivisorFilter(FilterContainer& filter_container) {
    int divisor = 10;
    filter_container.emplace_back([=](int value) { return value % divisor == 0;});
}

class Widget {
public:
    void addFilter() const {
        /*
        auto divisor_copy = divisor;
        filters.emplace_back([=](int value) {return value % divisor_copy == 0;});
        */
        filters.emplace_back([divisor = divisor](int value) {return value % divisor == 0;});
    }
private:
    int divisor;
};

int main(int argc, char *argv[])
{
    filters.emplace_back([](int value) { return value % 5 == 0; });
    addDivisorFilter(filters);

    std::vector<int> i_vec = {1, 2, 5, 10, 20, 23};
    for (auto &filter : filters) {
        auto it = std::find_if(std::begin(i_vec), std::end(i_vec), filter);
        if (it != std::end(i_vec)) {
            std::cout << *it << std::endl;
        }
    }
    return 0;
}
