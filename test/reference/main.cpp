#include <iostream>

int main()
{
    bool memory[100]{};

    memory[5] = false;

    std::cout << "bool 5 is " << (memory[5] ? "true" : "false") << "!\n";

    bool& test = memory[5];

    test = true;

    std::cout << "bool 5 is " << (memory[5] ? "true" : "false") << "!\n";

}