#include "../includes/ScalarConverter.hpp"

int main(int ac, char **av)
{
	if(ac != 2)
	{
        std::cerr << "Usage: ./convert [literal]" << std::endl;
    }
	
    const std::string s = av[1];
	
    ScalarConverter::convert(s);
}