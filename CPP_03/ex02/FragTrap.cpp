#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << _name << " is here!" << std::endl;
}

FragTrap::FragTrap(const FragTrap& copy) : ClapTrap(copy)
{
	*this = copy;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << _name << " dies!" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap& copy)
{
	this->ClapTrap::operator=(copy);
	return *this;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << _name << " high fives guys!" << std::endl;
}