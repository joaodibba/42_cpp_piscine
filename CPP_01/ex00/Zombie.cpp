#include "Zombie.hpp"

Zombie::Zombie(void) {
    this->name = "Default";
}

Zombie::Zombie(std::string newName) {
    this->name = newName;
}

void	Zombie::zombieActivity(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << name << ": No More BraiiiiiiinnnzzzZ..." << std::endl;
}
