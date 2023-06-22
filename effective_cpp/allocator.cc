#include <iostream>
#include <vector>
#include <limits>

template <typename T>
class MyAllocator {
public:
    using value_type = T;

    MyAllocator() noexcept = default;

    template <typename U>
    MyAllocator(const MyAllocator<U>& other) noexcept {}

    T* allocate(std::size_t n) {
        if (n > std::numeric_limits<std::size_t>::max() / sizeof(T)) {
            throw std::bad_alloc();
        }
        void* ptr = std::malloc(n * sizeof(T));
        if (!ptr) {
            throw std::bad_alloc();
        }
        return static_cast<T*>(ptr);
    }

    void deallocate(T* p, std::size_t n) noexcept {
        std::free(p);
    }
};

template <typename T>
using MyAllocVector = std::vector<T, MyAllocator<T>>;

int main() {
    MyAllocVector<int> m_ivec{1,2,3}; 
    /*
    std::vector<int, MyAllocator<int>> my_vec{{1, 2, 3}, MyAllocator<int>{}};
    for(auto &x: my_vec) {
        std::cout << x << " ";
    }
    std::cout << "\n";
    */
    return 0;
}
