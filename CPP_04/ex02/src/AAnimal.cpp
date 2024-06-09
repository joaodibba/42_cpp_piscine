#include "../includes/AAnimal.hpp"

AAnimal::AAnimal() : type("Animal")
{
	std::cout << "Animal default constructor called" << std::endl;
}

AAnimal::AAnimal(std::string type) : type(type)
{
	std::cout << "Animal type constructor called" << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "Animal destructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &animal)
{
	type = animal.type;
}

AAnimal &AAnimal::operator=(const AAnimal &animal)
{
if (this != &animal)
	type = animal.type;
return *this;
}

std::string AAnimal::getType() const
{
	return type;
}

void AAnimal::makeSound() const
{
	std::cout << this->type << ": " << "Animalistic sounds!" << std::endl;
}