#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{

protected:
	// protected so that derived classes can access them but cannot be instantiated directly
	ScavTrap();

public:
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap& copy);
	ScavTrap& operator=(const ScavTrap& right);
	~ScavTrap();

	void	attack(std::string const& target);
	void	guardGate();

};

#endif