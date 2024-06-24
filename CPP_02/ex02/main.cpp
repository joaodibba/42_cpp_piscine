#include "Fixed.hpp"

int main() {
	// Test default constructor
	Fixed a;
	std::cout << "value of a: " << a << std::endl;
	std::cout << "-----------------------------------------------" << std::endl;

	// Test integer constructor
	Fixed b(10);
	std::cout << "value of b: " << b << std::endl;
	std::cout << "-----------------------------------------------" << std::endl;

	// Test float constructor
	Fixed c(10.5f);
	std::cout << "value of c: " << c << std::endl;
	std::cout << "-----------------------------------------------" << std::endl;

	// Test copy constructor
	Fixed d(b);
	std::cout << "value of b (after copy constructor): " << b << std::endl;
	std::cout << "value of d (after copy constructor): " << d << std::endl;
	std::cout << "-----------------------------------------------" << std::endl;

	// Test copy assignment operator
	std::cout << "value of a: " << a << std::endl;
	std::cout << "value of c: " << c << std::endl;
	a = c;
	std::cout << "a (after assignment): " << a << std::endl;
	std::cout << "value of c: " << c << std::endl;
	std::cout << "-----------------------------------------------" << std::endl;

	// Test comparison operators
	std::cout << "value of a: " << a << std::endl;
	std::cout << "value of b: " << b << std::endl;
	std::cout << std::boolalpha;
	std::cout << a << " < " << b << " : " << (a < b) << std::endl;
	std::cout << a << " > " << b << " : " << (a > b) << std::endl;
	std::cout << a << " <= " << b << " : " << (a <= b) << std::endl;
	std::cout << a << " >= " << b << " : " << (a >= b) << std::endl;
	std::cout << a << " == " << b << " : " << (a == b) << std::endl;
	std::cout << a << " != " << b << " : " << (a != b) << std::endl;
	std::cout << std::noboolalpha;
	std::cout << "-----------------------------------------------" << std::endl;

	// Test arithmetic operators
	std::cout << b << " + " << c << " : " << b + c << std::endl;
	std::cout << b << " - " << c << " : " << b - c << std::endl;
	std::cout << b << " * " << c << " : " << b * c << std::endl;
	std::cout << b << " / " << c << " : " << b / c << std::endl;
	std::cout << "-----------------------------------------------" << std::endl;

	// Test increment and decrement operators
	Fixed i(10.1f);
	std::cout << "value of i: " << i++ << std::endl;
	std::cout << "value of i (after post-increment i++): " << i++ << std::endl;
	std::cout << "value of i (after post-increment i++): " << i << std::endl;
	std::cout << "value of i (pre-increment ++i): " << ++i << std::endl;
	std::cout << "value of i: " << i << std::endl;
	std::cout << "value of i (after post-decrement i--): " << i-- << std::endl;
	std::cout << "value of i (pre-decrement --i): " << --i << std::endl;
	std::cout << "final value of i: " << i << std::endl;
	std::cout << "-----------------------------------------------" << std::endl;

	// Test static min and max functions
	Fixed j(5.5f);
	Fixed k(7.69922f);  // Adjusted value for precision
	std::cout << "min(" << j << ", " << k << "): " << Fixed::min(j, k) << std::endl;
	std::cout << "max(" << j << ", " << k << "): " << Fixed::max(j, k) << std::endl;
	std::cout << "-----------------------------------------------" << std::endl;

	return (0);
}
