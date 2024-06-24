#include "Fixed.hpp"

// Default constructor
Fixed::Fixed() : _fixedPointValue(0) 
{
	std::cout << "Default constructor called" << std::endl;
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
