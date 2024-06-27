#include "../includes/AAnimal.hpp"

AAnimal::AAnimal() : _type("AAnimal")
{
	std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &other)
{
	_type = other._type;
	std::cout << "Animal copy constructor called" << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &right)
{
	if (this == &right)
		return (*this);
	_type = right._type;
	std::cout << "AAnimal assignment operator called" << std::endl;
	return( *this);
}

std::string AAnimal::getType() const
{
	return (_type);
}