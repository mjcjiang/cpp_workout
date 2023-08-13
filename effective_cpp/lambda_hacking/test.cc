#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> ivec = {1,2,23};
    /*
    auto it = std::find_if(ivec.begin(), ivec.end(), [](int val) {return 0 < val && val < 10;});
    if (it != ivec.end()) {
        std::cout << *it << std::endl;
    }
    */

    auto it = ivec.begin();
    while ((it = std::find_if(it, ivec.end(), [](int val) {
              return 0 < val && val < 10;
            })) != ivec.end()) {
        std::cout << *it << std::endl;
        it++;
    }
}
