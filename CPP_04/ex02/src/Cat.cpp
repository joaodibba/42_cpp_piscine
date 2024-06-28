#include "../includes/Cat.hpp"

Cat::Cat() : AAnimal(), brain (new Brain())
{
	_type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : AAnimal() , brain(new Brain(*other.brain))
{
	_type = other._type;
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
	AAnimal::operator=(right);
	_type = right._type;
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