#include "Zombie.hpp"

Zombie::Zombie(const std::string &name): _name(name)
{
}


Zombie::~Zombie(void)
{
	std::cout << _name << ": No More BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::announce( void )
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}