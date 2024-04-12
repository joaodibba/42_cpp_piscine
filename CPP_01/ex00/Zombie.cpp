#include "Zombie.hpp"

Zombie::Zombie(std::string name) 
{
    _name = name;
}

void	Zombie::zombieActivity(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << _name << ": No More BraiiiiiiinnnzzzZ..." << std::endl;
}
