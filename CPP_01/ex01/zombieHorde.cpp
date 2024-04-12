#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	if (N <= 0)
	{
		std::cerr << "Invalid number of zombies" << std::endl;
		return (NULL);
	}

	Zombie	*horde = new Zombie[N];
	if (!horde)
	{
		std::cerr << "Memory allocation failed" << std::endl;
		return (NULL);
	}
	for (int i = 0; i < N; i++){
		horde[i].setName(name);
	}
	return (horde);
}