#include <iostream>
#include <mutex>
#include <memory>

class Widget {
};

using MuxGuard = std::lock_guard<std::mutex>;

template<typename FuncType,typename MuxType, typename PtrType>
auto lockAndCall(FuncType func, MuxType& mutex, PtrType ptr) -> decltype(func(ptr)) {
    MuxGuard g(mutex);
    return func(ptr);
}

int f1(std::shared_ptr<Widget> spw) {
    std::cout << "This shared ptr function" << std::endl;
    return 1;
}

double f2(std::unique_ptr<Widget> spw) {
    std::cout << "This unique ptr function" << std::endl;
    return 1.0;
}

bool f3(Widget *pw) {
    std::cout << "This ptr function" << std::endl;
    return true;
}

int main() {
    std::mutex f1m, f2m, f3m;
    auto res1 = lockAndCall(f1, f1m, nullptr);
    return 0;
}
