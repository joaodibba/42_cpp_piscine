#include "Fixed.hpp"

// Default constructor
Fixed::Fixed() : _fixedPointValue(0) 
{
	std::cout << "Default constructor called" << std::endl;
}

// Integer constructor
Fixed::Fixed(const int value) 
{
	std::cout << "Int constructor called" << std::endl;
	_fixedPointValue = value << _fractionalBits;
}

// Float constructor
Fixed::Fixed(const float value) 
{
	std::cout << "Float constructor called" << std::endl;
	_fixedPointValue = roundf(value * (1 << _fractionalBits));
}

// Copy constructor
Fixed::Fixed(const Fixed &fixed) 
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

// Destructor
Fixed::~Fixed() 
{
	std::cout << "Destructor called" << std::endl;
}

// Copy assignment operator
Fixed &Fixed::operator=(const Fixed &fixed) 
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
		_fixedPointValue = fixed.getRawBits();
	return (*this);
}

// Gets the raw value of the Fixed point number
int Fixed::getRawBits(void) const 
{
	return (_fixedPointValue);
}

// Sets the raw value of the Fixed point number
void Fixed::setRawBits(const int raw) 
{
	_fixedPointValue = raw;
}

// Convert the Fixed point number to an integer
int Fixed::toInt(void) const 
{
	return (_fixedPointValue >> _fractionalBits);
}

// Convert the Fixed point number to a float
float Fixed::toFloat(void) const 
{
	return (static_cast<float>(_fixedPointValue) / (1 << _fractionalBits));
}


// "Greater than" operator
// Returns true if the value on the left is greater than the value on the right,
// otherwise it returns false.
bool Fixed::operator>(const Fixed &fixed) const 
{
	return (_fixedPointValue > fixed.getRawBits());
}

// "Less than" operator 
// Returns true if the value on the left is less than the value on the right,
// otherwise it returns false.
bool Fixed::operator<(const Fixed &fixed) const 
{
	return (_fixedPointValue < fixed.getRawBits());
}

// "Greater than or equal to" operator
// Returns true if the value on the left is greater than or equal to the value on the right,
// otherwise it returns false.
bool Fixed::operator>=(const Fixed &fixed) const 
{
	return (_fixedPointValue >= fixed.getRawBits());
}

// "Less than or equal to" operator
// Returns true if the value on the left is less than or equal to the value on the right,
// otherwise it returns false.
bool Fixed::operator<=(const Fixed &fixed) const 
{
	return (_fixedPointValue <= fixed.getRawBits());
}

// "Equal to" operator 
// Returns true if the value on the left is equal to the value on the right,
// otherwise it returns false.
bool Fixed::operator==(const Fixed &fixed) const 
{
	return (_fixedPointValue == fixed.getRawBits());
}

// "Not equal to" operator
// Returns true if the value on the left is not equal to the value on the right,
// otherwise it returns false.
bool Fixed::operator!=(const Fixed &fixed) const 
{
	return (_fixedPointValue != fixed.getRawBits());
}

// Addition of two Fixed numbers
Fixed Fixed::operator+(const Fixed &fixed) const 
{
	return (Fixed(toFloat() + fixed.toFloat()));
}

// Subtraction of two Fixed numbers
Fixed Fixed::operator-(const Fixed &fixed) const 
{
	return (Fixed(toFloat() - fixed.toFloat()));
}

// Multiplication of two Fixed numbers
Fixed Fixed::operator*(const Fixed &fixed) const 
{
	return (Fixed(toFloat() * fixed.toFloat()));
}

// Division of two Fixed numbers
Fixed Fixed::operator/(const Fixed &fixed) const 
{
	return (Fixed(toFloat() / fixed.toFloat()));
}

// Pre-increment operator
Fixed &Fixed::operator++() 
{
	_fixedPointValue = _fixedPointValue + 1;
	return (*this);
}

// Post-increment operator
Fixed Fixed::operator++(int) 
{
	Fixed tmp(*this);
	++(*this);
	return (tmp);
}

// Pre-decrement operator
Fixed &Fixed::operator--() 
{
	_fixedPointValue = _fixedPointValue - 1;
	return (*this);
}

// Post-decrement operator
Fixed Fixed::operator--(int) 
{
	Fixed tmp(*this);
	--(*this);
	return (tmp);
}

// Minimum of two Fixed numbers (non-const version)
Fixed &Fixed::min(Fixed &a, Fixed &b) 
{
	return (a < b ? a : b);
}

// Maximum of two Fixed numbers (non-const version)
Fixed &Fixed::max(Fixed &a, Fixed &b) 
{
	return (a > b ? a : b);
}

// Minimum of two Fixed numbers (const version)
const Fixed &Fixed::min(const Fixed &a, const Fixed &b) 
{
	return (a < b ? a : b);
}

// Maximum of two Fixed numbers (const version)
const Fixed &Fixed::max(const Fixed &a, const Fixed &b) 
{
	return (a > b ? a : b);
}

// Overloaded output operator
std::ostream &operator<<(std::ostream &out, const Fixed &fixed) 
{
	out << fixed.toFloat();
	return (out);
}