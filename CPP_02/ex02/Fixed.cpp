#include "Fixed.hpp"

// Default constructor
Fixed::Fixed() : _fixedPointValue(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
	// std::cout << "Int constructor called" << std::endl;
	_fixedPointValue = value << _fractionalBits;
}

Fixed::Fixed(const float value)
{
	// std::cout << "Float constructor called" << std::endl;
	_fixedPointValue = roundf(value * (1 << _fractionalBits));
}

// Copy constructor
Fixed::Fixed(const Fixed &fixed)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

//Copy assignment operator
Fixed	&Fixed::operator=(const Fixed &fixed)
{
	// TODO: protection here
	if (this == &fixed)
		return (*this);
	// std::cout << "Copy assignment operator called" << std::endl;
	_fixedPointValue = fixed.getRawBits();
	return (*this);
}

// Destructor
Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	return (_fixedPointValue);
}

void	Fixed::setRawBits(int const raw)
{
	_fixedPointValue = raw;
}

int		Fixed::toInt(void) const
{
	return (_fixedPointValue >> _fractionalBits);
}

float	Fixed::toFloat(void) const
{
	return ((float)_fixedPointValue / (1 << _fractionalBits));
}

// Comparison operators

bool	Fixed::operator>(const Fixed &fixed) const
{
	return (_fixedPointValue > fixed.getRawBits());
}

bool	Fixed::operator<(const Fixed &fixed) const
{
	return (_fixedPointValue < fixed.getRawBits());
}

bool	Fixed::operator>=(const Fixed &fixed) const
{
	return (_fixedPointValue >= fixed.getRawBits());
}

bool	Fixed::operator<=(const Fixed &fixed) const
{
	return (_fixedPointValue <= fixed.getRawBits());
}

bool	Fixed::operator==(const Fixed &fixed) const
{
	return (_fixedPointValue == fixed.getRawBits());
}

bool	Fixed::operator!=(const Fixed &fixed) const
{
	return (_fixedPointValue != fixed.getRawBits());
}

// Arithmetic operators

Fixed	Fixed::operator+(const Fixed &fixed) const
{
	return (Fixed(toFloat() + fixed.toFloat()));
}

Fixed	Fixed::operator-(const Fixed &fixed) const
{
	return (Fixed(toFloat() - fixed.toFloat()));
}

Fixed	Fixed::operator*(const Fixed &fixed) const
{
	return (Fixed(toFloat() * fixed.toFloat()));
}

Fixed	Fixed::operator/(const Fixed &fixed) const
{
	return (Fixed(toFloat() / fixed.toFloat()));
}

// Increment and decrement operators

Fixed	&Fixed::operator++()
{
	_fixedPointValue++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return (tmp);
}

Fixed	&Fixed::operator--()
{
	_fixedPointValue--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return (tmp);
}

// Static functions
Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b ? a : b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b ? a : b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b ? a : b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b ? a : b);
}

std::ostream	&operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}