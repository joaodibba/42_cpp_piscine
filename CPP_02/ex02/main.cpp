#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	{
		Fixed a = Fixed( 5.05f );
		Fixed b = Fixed( 2.02f );
		std::cout << a / b << std::endl;
		std::cout << a / 0 << std::endl;
		std::cout << b / 0 << std::endl;
		std::cout << Fixed( 0 ) / 0 << std::endl;
	}
	return 0;
}
