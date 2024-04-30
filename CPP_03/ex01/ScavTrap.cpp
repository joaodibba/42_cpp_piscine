#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	_guardGateMode = false;
	std::cout << "ScavTrap " << _name << " is here!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& copy) : ClapTrap(copy)
{
	*this = copy;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _name << " dies!" << std::endl;
}


ScavTrap &ScavTrap::operator=(const ScavTrap& copy)
{
	this->ClapTrap::operator=(copy);
	_guardGateMode = copy._guardGateMode;
	return *this;
}

void	ScavTrap::attack(std::string const& target)
{
	if (_hitPoints <= 0)
	{
		std::cout << "ScavTrap " << _name << " is dead and cannot attack!" << std::endl;
		return ;
	}
	if (_energyPoints <= 0)
	{
		std::cout << "ScavTrap " << _name << " is out of energy!" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << _name << " attacks " << target << std::endl;
	_energyPoints--;
}

void	ScavTrap::guardGate()
{
	_guardGateMode = !_guardGateMode;
	std::cout << "ScavTrap " << _name << " is now in " << (_guardGateMode ? "guard" : "attack") << " mode!" << std::endl;
}