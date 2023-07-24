#include <memory>

class Widget {
 public:
    Widget();
    ~Widget();
 private:
    struct Impl;
    //Impl *pImpl;
    std::unique_ptr<Impl> pImpl;
};
