#include "Fixed.hpp"

int main()
{
	Fixed a;
	Fixed b(a);
	Fixed c;

	c = b;

	std::cout 
			<< a.getRawBits() << std::endl
			<< b.getRawBits() << std::endl
			<< c.getRawBits() << std::endl;
	return (0);
}