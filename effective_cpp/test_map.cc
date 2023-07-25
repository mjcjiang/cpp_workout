#include <map>
#include <iostream>
#include <string>

int main() {
    std::map<std::string, std::map<std::string, int>> big_map;
    for (auto &e : big_map) {
        std::cout << e.first << std::endl;
    }
    return 0;
}
