#include "Zombie.hpp"

int main(void)
{
	int n = 5;
	Zombie *horde = zombieHorde(n, "Zombie");
	if (!horde)
		return (0);
	for (int i = 0; i < n; i++){
		horde[i].announce();
	}
	delete[] horde;
	return (0);
}