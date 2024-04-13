#include "Zombie.hpp"

int main ()
{
    Zombie	*zombie = newZombie("Zombie1");
	zombie->announce();
	if (!zombie)
		return (0);
	delete zombie;
    randomChump("Zombie2");
	return (0);
}