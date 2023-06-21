#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>
#include <iostream>
#include <unordered_map>

class Widget {
public:
    Widget() {
        score = gen_random(1, 100);
    }

    int get_score() {
        return score;
    }

    bool operator < (const Widget& rhs) const {
        return this->score < rhs.score;
    }
protected:
    int gen_random(int start, int end) {
        srand((unsigned)time(0));
        return start + rand() % (end - start);
    }
private:
    int score = 0;
};

void test_widget() {
    auto w1 = Widget();
    std::cout << w1.get_score() << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(1));

    auto w2 = Widget();
    std::cout << w2.get_score() << std::endl;
    if (w1 < w2) {
        std::cout << "w1 is less than w2" << std::endl;
    } else {
        std::cout << "w1 is not less than w2" << std::endl;
    }

    auto derefUPLess = [](const std::unique_ptr<Widget>& p1, const std::unique_ptr<Widget>& p2) {
        return *p1 < *p2;
    };

    auto p1 = std::unique_ptr<Widget>(new Widget());
    std::this_thread::sleep_for(std::chrono::seconds(1));
    auto p2 = std::unique_ptr<Widget>(new Widget());

    std::cout << p1->get_score() << " " << p2->get_score() << std::endl;

    if (derefUPLess(p1, p2)) {
        std::cout << "p1 is less than p2" << std::endl;
    } else {
        std::cout << "p1 is not less than p2" << std::endl;
    }
}

int main() {
    std::cout << "sizeof unsigned on this mechine: " << sizeof(unsigned) << std::endl;
    std::cout << "sizeof size_t: " << sizeof(size_t) << std::endl;
    std::unordered_map<std::string, int> m_map = {
        {"apple", 1},
        {"balala", 2},
        {"orange", 3}
    };

    for (auto &e : m_map) {
        e.second = 1;
    }

    for (const auto &e: m_map) {
        std::cout << e.first << " " << e.second << std::endl; 
    }

    return 0;
}