#include <iostream>
#include <new>
#include <string>

class ResourceGuard {
public:
    ResourceGuard(const std::string &res) : resource(res) {
        std::cout << "Acquire the " << resource << std::endl;
    }

    ~ResourceGuard() {
        std::cout << "Release the " << resource << std::endl;
    }
  private:
    const std::string resource;
};

int main(int argc, char *argv[])
{
    std::cout << std::endl;
    ResourceGuard resGuard1 {"memoryBlock1"};

    std::cout << "\nBefore local scope" << std::endl;
    {
        ResourceGuard resGuard2 {"memoryBlock2"};
    }
    std::cout << "After local scope" << std::endl;
    std::cout << std::endl;

    std::cout << "\nBefore try-catch block" << std::endl;
    try {
        ResourceGuard resGuard3 {"memoryBlock3"};
        throw std::bad_alloc();
    } catch (std::bad_alloc &e) {
        std::cout << e.what();
    }
    std::cout << "\nAfter try-catch block" << std::endl;
    std::cout << std::endl;
    return 0;
}

