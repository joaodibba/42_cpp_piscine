#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{

protected:
	// protected so that derived classes can access them but cannot be instantiated directly
	FragTrap();
public:
	FragTrap(std::string name);
	FragTrap(const FragTrap& copy);
	~FragTrap(); // destructor
	FragTrap& operator=(const FragTrap& right);

	void highFivesGuys(void);

};

#endif