#include <iostream>
#include <memory>
#include <unordered_map>
#include <string>

using UPtrMapSS = std::unique_ptr<std::unordered_map<std::string, std::string>>;

//typedef void (*FP)(int, const std::string&);
using FP = void (*)(int, const std::string&);

int main(void) {
    return 0;
}
