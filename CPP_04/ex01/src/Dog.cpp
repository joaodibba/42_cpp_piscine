#include "../includes/Dog.hpp"

Dog::Dog() : Animal(), brain(new Brain())
{
	_type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(), brain(new Brain(*other.brain))
{
	_type = other._type;
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete brain;
}

Dog &Dog::operator=(const Dog &right)
{
    if (this == &right)
        return (*this);
    Animal::operator=(right);
	_type = right._type;
    delete brain;
    brain = new Brain(*right.brain);
	std::cout << "Dog assignation operator called" << std::endl;
    return (*this);
}

void Dog::makeSound() const
{
	std::cout << _type << ": " << "Woof Woof!" << std::endl;
}

Brain *Dog::getBrain() const
{
	return (brain);
}