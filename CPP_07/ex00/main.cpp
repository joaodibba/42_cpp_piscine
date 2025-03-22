#include "whatever.hpp"
#include <iostream>
#include <string>

int main()
{
    std::string s1 = "string1";
    std::string s2 = "string2";

    std::cout << "Before swap: s1 = " << s1 << ", s2 = " << s2 << std::endl;

    swap(s1, s2);

    std::cout << "After swap:  s1 = " << s1 << ", s2 = " << s2 << std::endl;

    int first = 1;
    int second = 2;

    std::cout << "first = " << first << ", second = " << second << std::endl;

    std::cout << "min(first, second) = " << min(first, second) << std::endl;
    std::cout << "max(first, second) = " << max(first, second) << std::endl;

    return 0;
}
