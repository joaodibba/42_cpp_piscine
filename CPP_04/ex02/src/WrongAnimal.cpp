#include "../includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &wrongAnimal)
{
	_type = wrongAnimal._type;
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}


WrongAnimal &WrongAnimal::operator=(const WrongAnimal &rigth)
{
	if (this == &rigth)
		return (*this);
	_type = rigth._type;
	std::cout << "WrongAnimal assignation operator called" << std::endl;
	return (*this);
}

void WrongAnimal::makeSound() const
{
	std::cout << _type << ": " << "Wrong Animalistic sounds!" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (_type);
}
