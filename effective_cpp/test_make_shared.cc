#include <iostream>
#include <memory>
#include <vector>

class Test {
};

void test_refs(std::shared_ptr<Test> ptr) {
    std::cout << "In func " << ptr.use_count() << std::endl;
}

int main() {
    std::shared_ptr<Test> m_test(new Test);
    std::cout << "Before func call..." << m_test.use_count() << std::endl;
    test_refs(std::move(m_test));
    std::cout << "After func call..." << m_test.use_count() << std::endl;
    
    auto upv = std::make_shared<std::vector<int>>(10, 20);
    for (auto &e : *upv) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    auto initList = {10, 20};
    auto spv = std::make_shared<std::vector<int>>(initList);
    for (auto &e : *spv) {
        std::cout << e << " ";
    }
    std::cout << std::endl;
    return 0;
}
