#include "../includes/ScalarConverter.hpp"

int main(int ac, char **av)
{
    if (ac == 2)
        ScalarConverter::convert((const std::string)(av[1]));  // C style cast
    else
        std::cerr << "Usage: ./convert [literal]" << std::endl;
    return 0;
}
