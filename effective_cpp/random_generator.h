#include <iostream>
#include <chrono>
#include <random>

class UniIntRandomGen {
 public:
  UniIntRandomGen(int begin, int end) {
    _begin = begin;
    _end = end;

    seed = rd() ^ (
            (std::mt19937::result_type)
            std::chrono::duration_cast<std::chrono::seconds>(
                std::chrono::system_clock::now().time_since_epoch()
                ).count() +
            (std::mt19937::result_type)
            std::chrono::duration_cast<std::chrono::microseconds>(
                std::chrono::high_resolution_clock::now().time_since_epoch()
                ).count() );

    std::mt19937 gen(seed);
    _gen = gen;
    std::uniform_int_distribution<unsigned> distrib(_begin, _end);
    _distrib = distrib;
  }
 private:
  int _begin{0};
  int _end{0};
  std::random_device rd;
  std::mt19937::result_type seed;
  std::mt19937 _gen(1);
  std::uniform_int_distribution<unsigned> _distrib(0, 0);
};

int main() {
  return 0;
}
