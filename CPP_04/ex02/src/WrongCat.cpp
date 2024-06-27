#include "../includes/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	_type = "WrongCat";
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal()
{
	_type = other._type;
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &right)
{
	if (this == &right)
		return (*this);
	_type = right._type;
	std::cout << "WrongCat assignation operator called" << std::endl;
	return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << _type << ": " << "Wrong Meow Meow!" << std::endl;
}
