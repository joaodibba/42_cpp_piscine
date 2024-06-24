#include "Fixed.hpp"

// Default constructor
Fixed::Fixed() : _fixedPointValue(0) 
{
    // std::cout << "Default constructor called" << std::endl;
}

// Integer constructor
Fixed::Fixed(const int value) 
{
    // std::cout << "Int constructor called" << std::endl;
    _fixedPointValue = value << _fractionalBits;
}

// Float constructor
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

// Destructor
Fixed::~Fixed() 
{
    // std::cout << "Destructor called" << std::endl;
}

// Copy assignment operator
Fixed &Fixed::operator=(const Fixed &fixed) 
{
    // std::cout << "Copy assignment operator called" << std::endl;
    if (this != &fixed) {
        _fixedPointValue = fixed.getRawBits();
    }
    return *this;
}

int Fixed::getRawBits(void) const 
{
    return _fixedPointValue;
}

void Fixed::setRawBits(const int raw) 
{
    _fixedPointValue = raw;
}

int Fixed::toInt(void) const 
{
    return _fixedPointValue >> _fractionalBits;
}

float Fixed::toFloat(void) const 
{
    return static_cast<float>(_fixedPointValue) / (1 << _fractionalBits);
}

// Comparison operators
bool Fixed::operator>(const Fixed &fixed) const 
{
    return _fixedPointValue > fixed.getRawBits();
}

bool Fixed::operator<(const Fixed &fixed) const 
{
    return _fixedPointValue < fixed.getRawBits();
}

bool Fixed::operator>=(const Fixed &fixed) const 
{
    return _fixedPointValue >= fixed.getRawBits();
}

bool Fixed::operator<=(const Fixed &fixed) const 
{
    return _fixedPointValue <= fixed.getRawBits();
}

bool Fixed::operator==(const Fixed &fixed) const 
{
    return _fixedPointValue == fixed.getRawBits();
}

bool Fixed::operator!=(const Fixed &fixed) const 
{
    return _fixedPointValue != fixed.getRawBits();
}

// Arithmetic operators
Fixed Fixed::operator+(const Fixed &fixed) const 
{
    return Fixed(toFloat() + fixed.toFloat());
}

Fixed Fixed::operator-(const Fixed &fixed) const 
{
    return Fixed(toFloat() - fixed.toFloat());
}

Fixed Fixed::operator*(const Fixed &fixed) const 
{
    return Fixed(toFloat() * fixed.toFloat());
}

Fixed Fixed::operator/(const Fixed &fixed) const 
{
    return Fixed(toFloat() / fixed.toFloat());
}

// Increment and decrement operators
// Pre-increment
Fixed &Fixed::operator++() 
{
    _fixedPointValue += 1;
    return *this;
}

// Post-increment
Fixed Fixed::operator++(int) 
{
    Fixed tmp(*this);
    ++(*this);
    return tmp;
}

// Pre-decrement
Fixed &Fixed::operator--() 
{
    _fixedPointValue -= 1;
    return *this;
}

// Post-decrement
Fixed Fixed::operator--(int) 
{
    Fixed tmp(*this);
    --(*this);
    return tmp;
}

// Static functions
Fixed &Fixed::min(Fixed &a, Fixed &b) 
{
    return a < b ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) 
{
    return a > b ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) 
{
    return a < b ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) 
{
    return a > b ? a : b;
}

// Overloaded output operator
std::ostream &operator<<(std::ostream &out, const Fixed &fixed) 
{
    out << fixed.toFloat();
    return out;
}
