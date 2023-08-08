#include <iostream>
#include <array>
#include <vector>

int main() {
    std::vector<int> m_vec;
    m_vec.push_back(10);

    auto m_vec2 = std::move(m_vec);

    std::array<int, 3> m_arr = { 1, 2, 3 };
    auto m_arr2 = std::move(m_arr);
    for(auto& elem : m_arr) {
        std::cout << elem << std::endl;
    }
    return 0;
}
