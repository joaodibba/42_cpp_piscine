#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &dog)
{
	*this = dog;
}

Dog &Dog::operator=(const Dog &dog)
{
	type = dog.type;
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << this->type << ": " << "Woof Woof!" << std::endl;
}