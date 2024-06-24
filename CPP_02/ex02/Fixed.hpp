#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
private:
	int				_fixedPointValue; // The raw value of the fixed point number
	static const int _fractionalBits = 8; // The number of fractional bits
public:
	Fixed(); // Default constructor
	Fixed(const int value); // Int constructor
	Fixed(const float value); // Float constructor
	Fixed(const Fixed &fixed); // Copy constructor
	~Fixed(); // Destructor

	Fixed	&operator=(const Fixed &fixed); // Copy assignment operator
	int		getRawBits(void) const; // Returns the raw value of the fixed point number
	void	setRawBits(const int raw); // Sets the raw value of the fixed point number
	int		toInt(void) const; // Returns the fixed point number as an int
	float	toFloat(void) const; // Returns the fixed point number as a float

	bool	operator>(const Fixed &fixed) const;
	bool	operator<(const Fixed &fixed) const;
	bool	operator>=(const Fixed &fixed) const;
	bool	operator<=(const Fixed &fixed) const;
	bool	operator==(const Fixed &fixed) const;
	bool	operator!=(const Fixed &fixed) const;

	Fixed	operator+(const Fixed &fixed) const;
	Fixed	operator-(const Fixed &fixed) const;
	Fixed	operator*(const Fixed &fixed) const;
	Fixed	operator/(const Fixed &fixed) const;

	Fixed	&operator++();
	Fixed	operator++(int);
	Fixed	&operator--();
	Fixed	operator--(int);

	// Static functions
	static Fixed	&min(Fixed &a, Fixed &b);
	static Fixed	&max(Fixed &a, Fixed &b);
	static const Fixed	&min(const Fixed &a, const Fixed &b);
	static const Fixed	&max(const Fixed &a, const Fixed &b);
};

std::ostream	&operator<<(std::ostream &out, const Fixed &fixed);

#endif