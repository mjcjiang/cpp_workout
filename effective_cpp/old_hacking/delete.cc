#include <iostream>

bool is_lucky(int number) {
    if (number % 2 == 0) {
        return true;
    }

    return false;
}

bool is_lucky(char) = delete;
bool is_lucky(double) = delete;

template<typename T>
void processPointer(T* ptr);

template<>
void processPointer(void *ptr) = delete;

template<>
void processPointer(char *ptr) = delete;

template<>
void processPointer(const char *ptr) = delete;

class Widget {
public:
    template<typename T>
    void processPointer(T* ptr);
};

int main() {
    /*
    if (is_lucky('a')) {
        std::cout << 'a' << "is a lucky number" << std::endl;
    } else {
        std::cout << 'a' << "is not a lucky number" << std::endl;
    }
    */
    //processPointer("hello");
    return 0;
}
