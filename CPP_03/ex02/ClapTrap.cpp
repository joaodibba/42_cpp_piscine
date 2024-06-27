#include "ClapTrap.hpp"

// Default constructor
// This constructor is protected and cannot be called from outside the class
ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap is here!" << std::endl;
}

// Constructor
// This constructor is public and can be called from outside the class
ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << _name << " is here!" << std::endl;
}

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap& copy) : _name(copy._name), _hitPoints(copy._hitPoints), _energyPoints(copy._energyPoints), _attackDamage(copy._attackDamage)
{
	std::cout << _name << " is copied!" << std::endl;
}

// Destructor
ClapTrap::~ClapTrap()
{
	std::cout << _name << " dies!" << std::endl;
}

// Copy assignment operator
ClapTrap& ClapTrap::operator=(const ClapTrap& right)
{
    if (this == &right)
        return *this; // Self-assignment check
    _name = right._name;
    _hitPoints = right._hitPoints;
    _energyPoints = right._energyPoints;
    _attackDamage = right._attackDamage;

    std::cout << _name << " is assigned!" << std::endl;
    return *this;
}


/*
	@brief 
			This function is called when a ClapTrap instance attacks.

	@param 	target 
			The name of the target to attack
*/
void ClapTrap::attack(std::string const& target)
{
	if (_hitPoints == 0)
	{
		std::cout << _name << " is dead and cannot attack!" << std::endl;
		return;
	}
	if (_energyPoints == 0)
	{
		std::cout << _name << " is out of energy!" << std::endl;
		return;
	}
	if (target.empty())
	{
		std::cout << _name << " attacks nothing!" << std::endl;
		return;
	}
	if (_attackDamage == 0)
	{
		std::cout << _name << " has no attack damage!" << std::endl;
		return;
	}
	std::cout << _name << " attacks " << target << std::endl;
	_energyPoints--;
}

/*
	@brief 
			This function is called when the ClapTrap instance takes damage.

	@param 	amount 
			The amount of damage to take
*/
void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints == 0)
	{
		std::cout << _name << " is already dead!" << std::endl;
		return;
	}
	if (amount == 0)
	{
		std::cout << _name << " takes no damage!" << std::endl;
		return;
	}

	unsigned int damage = (amount > _hitPoints) ? _hitPoints : amount;
	std::cout << _name << " takes " << damage << " points of damage!" << std::endl;
	_hitPoints -= damage;

	if (_hitPoints == 0)
		std::cout << _name << " is dead!" << std::endl;
}

/*
	@brief 
			This function is called when the ClapTrap instance is repaired.

	@param 	amount 
			The amount of hit points to repair
*/
void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints == 0)
	{
		std::cout << _name << " is dead and cannot be repaired!" << std::endl;
		return;
	}
	if (_energyPoints == 0)
	{
		std::cout << _name << " is out of energy!" << std::endl;
		return;
	}

	if (_hitPoints == 10)
	{
		std::cout << _name << " is already at full health!" << std::endl;
		return;
	}
	if (amount == 0)
	{
		std::cout << _name << " is not repaired!" << std::endl;
		return;
	}
	unsigned int repairAmount = (_hitPoints + amount > 10) ? 10 - _hitPoints : amount;
	_hitPoints = (_hitPoints + amount > 10) ? 10 : _hitPoints + repairAmount;

	std::cout << _name << " is repaired for " << repairAmount << " points and now has " << _hitPoints << " hit points!" << std::endl;
	_energyPoints--;
}

// Getters
std::string ClapTrap::getName() const { return (_name); }
int ClapTrap::getHitPoints() const { return (_hitPoints); }
int ClapTrap::getEnergyPoints() const { return (_energyPoints); }
int ClapTrap::getAttackDamage() const { return (_attackDamage); }