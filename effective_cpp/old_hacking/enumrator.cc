#include <iostream>

int main(void) {
    enum class Color { black, white, red };
    Color c = Color::white;
    auto cv = static_cast<int>(c);
    std::cout << cv << std::endl;
    return 0;
}
