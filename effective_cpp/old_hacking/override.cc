#include <iostream>
#include <memory>

/*
class Base {
public:
  virtual void doWork() {
    std::cout << "This is doWork in Base class" << std::endl;
  }
};

class Derived: public Base {
public:
  virtual void doWork() {
    std::cout << "This is doWork in Derived class" << std::endl;
  }
};
*/

class Base {
public:
  virtual void mf1() const {
    std::cout << "This is mf1 in base class." << std::endl;
  }

  virtual void override() {
    std::cout << "This is the override function in base class." << std::endl;
  }
};

class Derived: public Base {
public:
  virtual void mf1() const override {
    std::cout << "This is mf1 in derived class." << std::endl;
  }

  virtual void override() override {
    std::cout << "This is the override function in derived class." << std::endl;
  }
};

int main() {
  std::unique_ptr<Base> upb = std::make_unique<Derived>();
  upb->mf1(); 
  return 0;
}
