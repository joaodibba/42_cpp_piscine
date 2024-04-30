#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat default constructor called" << std::endl;
}
WrongCat::WrongCat(std::string type)
{
	this->type = type;
}
WrongCat::WrongCat(const WrongCat &wrongCat)
{
	*this = wrongCat;
}

WrongCat &WrongCat::operator=(const WrongCat &wrongCat)
{
	type = wrongCat.type;
	return *this;
}

WrongCat::~WrongCat()
{
}

void WrongCat::makeSound() const
{
	std::cout << this->type << ": " << "Wrong Meow Meow!" << std::endl;
}
