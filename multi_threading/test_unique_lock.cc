#include <iostream>
#include <array>
#include <algorithm>

template <typename T, size_t N>
class BigClass {
public:
    BigClass(const T& init) {
        for (auto &x : members) 
            x = init;
    }

    void fill_member(size_t idx, T &member) {
        if (idx < N) {
            members[idx] = member;
        }
    }

    template <typename T_, size_t N_>
    friend void swap(BigClass<T_, N_>& left, BigClass<T_, N_>& right);

    void tell_self() {
        for (auto &x : members) {
            std::cout << x << " ";
        }
        std::cout << std::endl;
    }
private:
    std::array<T, N> members;
};

template <typename T, size_t N>
void swap(BigClass<T, N> &left, BigClass<T, N> &right) {
    std::swap(left.members, right.members);
}

int main(int argc, char *argv[])
{
    auto a = BigClass<int, 10>(1);
    auto b = BigClass<int, 10>(2);
    std::cout << "Before swap...." << std::endl;
    a.tell_self();
    b.tell_self();
    swap(a, b);
    std::cout << "After swap...." << std::endl;
    a.tell_self();
    b.tell_self();
    return 0;
}

