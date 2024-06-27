#include "FragTrap.hpp"

// Default constructor
// This constructor is protected and cannot be called from outside the class
FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap arrived from the Sky!" << std::endl;
}

// Constructor
// This constructor is public and can be called from outside the class
FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << _name << "arrived from the Sky!" << std::endl;
}

// Copy constructor
FragTrap::FragTrap(const FragTrap& copy) : ClapTrap(copy._name)
{
	_hitPoints = copy._hitPoints;
	_energyPoints = copy._energyPoints;
	_attackDamage = copy._attackDamage;
	std::cout << "FragTrap " << _name << " is copied!" << std::endl;
}

// Destructor
FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << _name << " returned to the heavens." << std::endl;
}

// Copy assignment operator
FragTrap &FragTrap::operator=(const FragTrap& right)
{
	if (this == &right)
		return (*this);
	this->ClapTrap::operator=(right);
	std::cout << "FragTrap " << _name << " is assigned!" << std::endl;
	return (*this);
}

// Special member functions
void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << _name << " went for a high five!" << std::endl;
}