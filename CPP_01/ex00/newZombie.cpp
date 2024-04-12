#include "Zombie.hpp"

Zombie* newZombie( std::string name )
{
	Zombie *zombie = new Zombie(name);
	if (!zombie)
		return (NULL);
	zombie->zombieActivity();
	return(zombie);
}