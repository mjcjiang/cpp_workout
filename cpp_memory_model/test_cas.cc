#include <iostream>
#include <atomic>

std::atomic_int ai;
int tst_val = 4;
int new_val = 5;
bool exchanged = false;

void vals_out() {
    std::cout << "ai= " << ai
              << " tst_val= " << tst_val
              << " new_val= " << new_val
              << " exchanged= " << std::boolalpha << exchanged
              << "\n";
}

int main() {
    ai = 3;
    vals_out();

    exchanged = ai.compare_exchange_strong(tst_val, new_val);
    vals_out();

    exchanged = ai.compare_exchange_strong(tst_val, new_val);
    vals_out();
    return 0;
}
