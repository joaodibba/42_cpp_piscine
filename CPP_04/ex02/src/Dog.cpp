#include "../includes/Dog.hpp"

Dog::Dog() : AAnimal("Dog")
{
	std::cout << "Dog default constructor called" << std::endl;
	brain = new Brain();
}

Dog::Dog(const Dog &dog) : AAnimal(dog), brain(NULL)
{
	*this = dog;
}

// Dog &Dog::operator=(const Dog &dog)
// {
// 	if (this != &dog)
// 	{
// 		this->Animal::operator=(dog);
// 		if (brain)
// 			delete brain;
// 		brain = new Brain(*dog.brain);
// 	}
// 	return *this;
// }

Dog &Dog::operator=(const Dog &other)
{
    if (this == &other)
        return (*this);
    this->AAnimal::operator=(other);
    if (this->brain)
        delete this->brain;
    this->brain = new Brain(*other.brain);
    return (*this);
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << this->type << ": " << "Woof Woof!" << std::endl;
}

Brain *Dog::getBrain() const
{
	return brain;
}