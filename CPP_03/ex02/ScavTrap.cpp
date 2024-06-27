#include "ScavTrap.hpp"

// Default constructor
// This constructor is protected and cannot be called from outside the class
ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap was born!" << std::endl;
}

// Constructor
// This constructor is public and can be called from outside the class
ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap " << _name << " was born!" << std::endl;
}

// Copy constructor
ScavTrap::ScavTrap(const ScavTrap& copy) : ClapTrap(copy._name)
{
	_hitPoints = copy._hitPoints;
	_energyPoints = copy._energyPoints;
	_attackDamage = copy._attackDamage;
	std::cout << "ScavTrap " << _name << " is copied!" << std::endl;
}

// Destructor
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _name << " dies!" << std::endl;
}

// Copy assignment operator
ScavTrap &ScavTrap::operator=(const ScavTrap& right)
{
	if (this == &right)
		return (*this); // Self-assignment check
	this->ClapTrap::operator=(right); 
	std::cout << "ScavTrap " << _name << " is assigned!" << std::endl;
	return (*this);
}

/*
	@brief 
			This function is called when a ScavTrap instance attacks.

	@param 	target 
			The name of the target to attack
*/
void	ScavTrap::attack(std::string const& target)
{
	if (_hitPoints == 0)
	{
		std::cout << "ScavTrap " << _name << " is dead and cannot attack!" << std::endl;
		return ;
	}
	if (_energyPoints == 0)
	{
		std::cout << "ScavTrap " << _name << " is out of energy!" << std::endl;
		return ;
	}
	if (target.empty())
	{
		std::cout << "ScavTrap " << _name << " attacks the air!" << std::endl;
		return ;
	}
	if (_attackDamage == 0)
	{
		std::cout << "ScavTrap " << _name << " has no attack damage!" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << _name << " attacks " << target << std::endl;
	_energyPoints--;
}

// Special member function
void	ScavTrap::guardGate()
{
	static bool guardGate = false;

	guardGate = !guardGate;

	if (guardGate)
		std::cout << "ScavTrap " << _name << " is now in Guard Gate mode!" << std::endl;
	else
		std::cout << "ScavTrap " << _name << " is now out of Guard Gate mode!" << std::endl;
}