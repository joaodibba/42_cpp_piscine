#include "Fixed.hpp"

int main( void )
{
	// Fixed a;
	// Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	// std::cout << a << std::endl;
	// std::cout << ++a << std::endl;
	// std::cout << a << std::endl;
	// std::cout << a++ << std::endl;
	// std::cout << a << std::endl;

	// std::cout << b << std::endl;

	// std::cout << Fixed::max( a, b ) << std::endl;

	// {
	// 	Fixed a = Fixed( 5.05f );
	// 	Fixed b = Fixed( 2.02f );
	// 	std::cout << a / b << std::endl;
	// 	std::cout << a / 0 << std::endl;
	// 	std::cout << b / 0 << std::endl;
	// 	std::cout << Fixed( 0 ) / 0 << std::endl;
	// }
	return 0;
}

// int main( void )
// {
//     {
//         Fixed a;
//         Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
//         std::cout << a << std::endl;
//         std::cout << ++a << std::endl;
//         std::cout << a << std::endl;
//         std::cout << a++ << std::endl;
//         std::cout << a << std::endl;
//         std::cout << b << std::endl;
//         std::cout << Fixed::max( a, b ) << std::endl;
//     }
//     std::cout << "----My tests---" << std::endl;
//     {
//         std::cout << "Decrement" << std::endl;
//         Fixed g(10);
//         std::cout <<  g << std::endl;
//         std::cout << --g << std::endl;
//         std::cout << g << std::endl;
//         std::cout << g-- << std::endl;
//         std::cout << g << std::endl;
//     }
//     {
//         std::cout << "min and max" << std::endl;
//         Fixed a;
//         Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
//         std::cout << b << std::endl;
//         std::cout << Fixed::max(a, b) << std::endl;
//         Fixed const c(3.5f);
//         Fixed const d(4.5f);
//         std::cout << Fixed::max(c, d) << std::endl;
//         Fixed e(2.5f);
//         Fixed f(1.5f);
//         std::cout << Fixed::min(e, f) << std::endl;
//         std::cout << Fixed::min(c, d) << std::endl;
//     }
//     {
//         Fixed b, c, d;
//         b.setRawBits(42);
//         c.setRawBits(10);

//         std::cout << "Comparisons" << std::endl;
//         std::cout << (b > c) << std::endl;
//         std::cout << (b < c) << std::endl;
//         c.setRawBits(42);
//         std::cout << (b <= c) << std::endl;
//         std::cout << (b >= c) << std::endl;
//         b.setRawBits(100);
//         std::cout << (b == c) << std::endl;
//         std::cout << (c == c) << std::endl;
//         std::cout << (b != c) << std::endl;

//         std::cout << "Arithmetic" << std::endl;
//         std::cout << b + c << std::endl;
//         d = b - c;
//         std::cout << d << std::endl;
//         std::cout << b * c << std::endl;
//         try 
//         {
//             std::cout << b / c << std::endl;
//             d = b / c;
//             c.setRawBits(0);
//             throw (0);
//             std::cout << b / c << std::endl;
//         }
//         catch (int num)
//         {
//             std::cout << "Denominator cannot be 0" << std::endl;
//         }

//         return 0;
//     }
// }