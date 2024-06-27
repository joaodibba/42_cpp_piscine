#include "../includes/Dog.hpp"

Dog::Dog() : Animal()
{
	_type = "Dog";
	brain = new Brain();
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal()
{
	_type = other._type;
	brain = new Brain(*other.brain);
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &right)
{
    if (this == &right)
        return (*this);
    this->Animal::operator=(right);
    if (brain)
        delete brain;
    this->brain = new Brain(*right.brain);
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