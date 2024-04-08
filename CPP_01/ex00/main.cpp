#include "Zombie.hpp"

int main ()
{
    Zombie	*zombie1;

	zombie1 = newZombie("Marvin");
    randomChump("Marvin's Friend");

	delete zombie1;
	return (0);
}