#include "iter.hpp"
#include <iostream>
#include <string>

void printInt(int& x) {
    std::cout << "Function pointer: " << x << std::endl;
}

template <typename T>
void printTemplate(T& x) {
    std::cout << "Template function: " << x << std::endl;
}

struct PrintFunctor {
    template <typename T>
    void operator()(T& x) const {
        std::cout << "Functor: " << x << std::endl;
    }
};

int main() {
    int numbers[] = {1, 2, 3};
    std::string words[] = {"hello", "world"};

    std::cout << "Using function pointer" << std::endl;
    iter(numbers, 3, printInt);

    std::cout << "Using instantiated function template" << std::endl;
    iter(numbers, 3, printTemplate<int>);
    iter(words, 2, printTemplate<std::string>);

    std::cout << "Using functor" << std::endl;
    PrintFunctor functor;
    iter(numbers, 3, functor);
    iter(words, 2, functor);

    return 0;
}
