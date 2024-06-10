#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << _name << " is here!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy)
{
	*this = copy;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " dies!" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& copy)
{
	// TODO: protection here. !!!bro just protect self assessment everywhere!!!
	_name = copy._name;
	_hitPoints = copy._hitPoints;
	_energyPoints = copy._energyPoints;
	_attackDamage = copy._attackDamage;
	return *this;
}

void	ClapTrap::attack(std::string const& target)
{
	if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " is dead and cannot attack!" << std::endl;
		return ;
	}
	if (_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " is out of energy!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << " attacks " << target << std::endl;
	_energyPoints--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " is dead!" << std::endl;
		return ;
	}
	if (amount <= 0)
	{
		std::cout << "ClapTrap " << _name << " takes no damage!" << std::endl;
		return ;
	}
	_hitPoints = (_hitPoints < amount) ? 0 : _hitPoints - amount;

	std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
	if (_hitPoints <= 0)
		std::cout << "ClapTrap " << _name << " is dead!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " is dead and cannot be repaired!" << std::endl;
		return ;
	}
	if (_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " is out of energy!" << std::endl;
		return ;
	}
	if (_hitPoints == 10)
		std::cout << "ClapTrap " << _name << " is already at full health!" << std::endl;
	else
	{
		_hitPoints = (_hitPoints + amount > 10) ? 10 : _hitPoints;
		std::cout << "ClapTrap " << _name << " is repaired for " << amount << " points and now has " << _hitPoints << " hit points!" << std::endl;
		_energyPoints--;
	}
}

std::string	ClapTrap::getName() const
{
	return _name;
}

int	ClapTrap::getHitPoints() const
{
	return _hitPoints;
}

int	ClapTrap::getEnergyPoints() const
{
	return _energyPoints;
}

int	ClapTrap::getAttackDamage() const
{
	return _attackDamage;
}

void ClapTrap::roundResult() const
{
	std::cout   << BLUE << _name << RESET << "  --> " << YELLOW << _hitPoints
				<< RESET << " hit points and " << YELLOW << _energyPoints
				<< RESET <<  " energy points" << std::endl;
}