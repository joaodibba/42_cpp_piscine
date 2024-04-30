#include "../includes/Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat default constructor called" << std::endl;
	brain = new Brain();
}

Cat::Cat(const Cat &cat)
{
	*this = cat;
}

Cat &Cat::operator=(const Cat &cat)
{
	if (this == &cat)
		return (*this);

	this->Animal::operator=(cat);
	if (brain)
		delete brain;
	brain = new Brain(*cat.brain);
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete brain;
}

void Cat::makeSound() const
{
	std::cout << this->type << ": " << "Meow Meow!" << std::endl;
}

Brain *Cat::getBrain() const
{
	return brain;
}
