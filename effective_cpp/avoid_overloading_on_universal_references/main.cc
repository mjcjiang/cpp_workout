#include <set>
#include <string>
#include <chrono>
#include <iostream>
#include <map>
#include <typeinfo>

std::set<std::string> names;
std::map<int, std::string> name_table = {
    {1001, "zhangshan"},
    {2001, "lishi"}
};

std::string nameFromIdx(int index) {
    if (name_table.find(index) != name_table.end()) {
        return name_table[index];
    }

    return "";
}

/*
void logAndAdd(const std::string& name) {
    auto now = std::chrono::system_clock::now();
    std::cout << now.time_since_epoch().count() << std::endl;
    names.emplace(name);
}
*/

template<typename T>
void logAndAdd(T&& name) {
    auto now = std::chrono::system_clock::now();
    std::cout << "a: " << now.time_since_epoch().count() << std::endl;
    names.emplace(std::forward<T>(name));
}

void logAndAdd(int idx) {
    auto now = std::chrono::system_clock::now();
    std::cout << "b: " << now.time_since_epoch().count() << std::endl;
    names.emplace(name_table[idx]);
}

/*
class Point{
public:
    explicit Point(int x = 0, int y = 0):
        x(x), y(y)
    {
    }
    int x, y;
};

void displayPoint(const Point& pt) {
    std::cout << pt.x << ":" << pt.y << std::endl;
}
*/

class Person {
public:
    template<typename T>
    explicit Person(T&& n)
        :name(std::forward<T>(n)) {}

    explicit Person(int idx)
        :name(nameFromIdx(idx)) {}
private:
    std::string name;
};

int main() {
    /*
    std::string petName("Darla");
    logAndAdd(petName);
    logAndAdd(std::string("Shasha"));
    logAndAdd("Jakey");

    logAndAdd(1002);
    logAndAdd(short(1001));
    */

    const Person p("jakey");
    auto cloneOfP(p);
    return 0;
}
