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
Fixed::Fixed(const Fixed &fixed) : _fixedPointValue(fixed._fixedPointValue)
{
	std::cout << "Copy constructor called" << std::endl;
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

std::ostream	&operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}