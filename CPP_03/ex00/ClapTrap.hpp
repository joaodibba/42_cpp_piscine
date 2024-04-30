#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP

# include <iostream>

class ClapTrap
{
protected:
	std::string			_name;
	unsigned int		_hitPoints;
	unsigned int		_energyPoints;
	unsigned int		_attackDamage;
	ClapTrap(); // private constructor
public:
	ClapTrap(std::string name); // constructor
	ClapTrap(const ClapTrap& copy); // copy constructor
	~ClapTrap(); // destructor
	ClapTrap& operator=(const ClapTrap& copy); // assignation operator

	void		attack(std::string const& target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);
	std::string	getName() const;
	int			getHitPoints() const;
	int			getEnergyPoints() const;
	int			getAttackDamage() const;
	void		roundResult() const; // remove
};

# define GREEN "\033[32m"
# define PURPLE "\033[35m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define RESET "\033[0m"

#endif