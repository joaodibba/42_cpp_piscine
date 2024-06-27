#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP

# include <iostream>

class ClapTrap
{

protected:
	// Protected attributes to allow derived classes to access 
	// them but not allow direct access from outside the class hierarchy
	std::string			_name;
	unsigned int		_hitPoints;
	unsigned int		_energyPoints;
	unsigned int		_attackDamage;
	// Protected constructor to prevent instantiation of ClapTrap without a name
	ClapTrap();
public:
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap& copy);
	~ClapTrap();
	ClapTrap& operator=(const ClapTrap& right);

	void		attack(std::string const& target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);

	// Getters to allow read access to outside the class hierarchy
	std::string	getName() const;
	int			getHitPoints() const;
	int			getEnergyPoints() const;
	int			getAttackDamage() const;

};

#endif