#include <atomic>
#include <iostream>
#include <cassert>
#include <type_traits>
#include <memory>

template <typename T>
//requires std::is_integral<T>::value
T fetch_mult(std::atomic<T> &shared, T multi) {
    T oldValue = shared.load();
    while(!shared.compare_exchange_strong(oldValue, oldValue * multi));
    return oldValue;
}

struct User {
public:
    User(int age) : age(age) {}
    void tell_message() {
        std::cout << "Age: " << age << "\n";
    }
private:
    int age;
};

int main() {
  /*
  int intArray[5];
  std::atomic<int*> p(intArray);

  for (int i = 0; i < 5; i++) {
      *p = i + 1;
      p += 1;
  }

  assert(p.load() == &intArray[5]);
  */
    
    std::atomic<int> i(1);
    i += 1;
    std::cout << "now i is: " << i.load() << std::endl;
    i -= 1;
    std::cout << "now i is: " << i.load() << std::endl;

    std::cout << fetch_mult(i, 10) << std::endl;
    std::cout << "now i is: " << i.load() << std::endl;

    std::atomic<User> u(User(10));
    auto u1 = User(10);
    while(!u.compare_exchange_strong(u1, User(12)));
    u.load().tell_message();
    
    return 0;
}
