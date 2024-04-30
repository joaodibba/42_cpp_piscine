#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	private:
		FragTrap(); // private constructor

	public:
		FragTrap(std::string name); // constructor
		FragTrap(const FragTrap& copy); // copy constructor
		~FragTrap(); // destructor
		FragTrap& operator=(const FragTrap& copy); // assignation operator

		void highFivesGuys(void);
		
		void attack(std::string const& target);
		void takeDamage(unsigned int amount);
};

#endif