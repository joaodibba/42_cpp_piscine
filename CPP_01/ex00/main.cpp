#include "Zombie.hpp"

int main ()
{
    Zombie	*zombie = newZombie("Zombie1");
	if (!zombie)
		return (0);
    randomChump("Zombie2");

	delete zombie;
	return (0);
}