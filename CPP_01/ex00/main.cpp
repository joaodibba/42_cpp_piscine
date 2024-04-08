#include "Zombie.hpp"

int main ()
{
    Zombie	*zombie1;

	zombie1 = newZombie("Zombie1");
	if (!zombie1)
		return (0);
    randomChump("Zombie2");

	delete zombie1;
	return (0);
}