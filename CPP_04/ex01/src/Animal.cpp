#include "../includes/Animal.hpp"

Animal::Animal() : _type("Animal")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal &other)
{
	_type = other._type;
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &right)
{
	if (this == &right)
		return (*this);
	_type = right._type;
	std::cout << "Animal assignment operator called" << std::endl;
	return( *this);
}

std::string Animal::getType() const
{
	return (_type);
}

void Animal::makeSound() const
{
	std::cout << _type << ": " << "Animalistic sounds!" << std::endl;
}