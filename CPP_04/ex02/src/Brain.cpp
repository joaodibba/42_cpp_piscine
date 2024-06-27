#include "../includes/Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain &other)
{
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = other.ideas[i];
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &right)
{
	if (this == &right)
		return (*this);
	for (int i = 0; i < 100; i++)
		ideas[i] = right.ideas[i];
	return (*this);
}

void Brain::setIdea(int index, std::string idea)
{
	if (index < 0 || index >= 100)
		throw std::out_of_range("Index out of range");
	ideas[index] = idea;
}

std::string Brain::getIdea(int index) const
{
	if (index < 0 || index >= 100)
		throw std::out_of_range("Index out of range");
	return (ideas[index]);
}