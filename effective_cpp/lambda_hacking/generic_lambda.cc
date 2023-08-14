#include <iostream>

int main(int argc, char *argv[])
{
    auto echo = [](const auto &param) {
        std::cout << param << std::endl;
    };
    
    echo(1);
    echo(2);
    echo("hello lambda");
    return 0;
}
