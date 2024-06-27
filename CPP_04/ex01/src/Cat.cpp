#include "../includes/Cat.hpp"

Cat::Cat() : Animal()
{
	_type = "Cat";
	brain = new Brain();
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal()
{
	_type = other._type;
	brain = new Brain(*other.brain);
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete brain;
}

Cat &Cat::operator=(const Cat &right)
{
	if (this == &right)
		return (*this);
	this->Animal::operator=(right);
	if (brain)
		delete brain;
	brain = new Brain(*right.brain);
	std::cout << "Cat assignation operator called" << std::endl;
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << _type << ": " << "Meow Meow!" << std::endl;
}

Brain *Cat::getBrain() const
{
	return (brain);
}