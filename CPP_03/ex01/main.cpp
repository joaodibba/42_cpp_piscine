#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>
#include <cstdlib> 

int main() {
	std::cout << "--- ClapTrap vs ScavTrap Fight ---" << std::endl;
	{

		// Create one ClapTrap and one ScavTrap instance
		ClapTrap clap("CL4P-TP");
		ScavTrap scav("SC4V-TP");

		std::cout << "\n--- Initial Stats ---" << std::endl;

		std::cout << clap.getName() << " has " << clap.getHitPoints() << " hit points, "
				  << clap.getEnergyPoints() << " energy points and " 
				  << clap.getAttackDamage() << " attack damage." << std::endl;
		std::cout << scav.getName() << " has " << scav.getHitPoints() << " hit points, "
				  << scav.getEnergyPoints() << " energy points and "
				  << scav.getAttackDamage() << " attack damage." << std::endl;

		std::cout << "\n--- Fight Begins ---" << std::endl;

		while (clap.getHitPoints() > 0 && scav.getHitPoints() > 0) {
			if (rand() % 2 == 0) {
				if (clap.getEnergyPoints() > 0) {
					clap.attack(scav.getName());
					scav.takeDamage(clap.getAttackDamage());
				}
			} else {
				if (scav.getEnergyPoints() > 0) {
					scav.attack(clap.getName());
					clap.takeDamage(scav.getAttackDamage());
				}
			}

			std::cout << "\n--- Current Stats ---" << std::endl;

			std::cout << clap.getName() << " has " << clap.getHitPoints() << " hit points, "
					  << clap.getEnergyPoints() << " energy points." << std::endl;
			std::cout << scav.getName() << " has " << scav.getHitPoints() << " hit points, "
					  << scav.getEnergyPoints() << " energy points." << std::endl;
		}

		scav.guardGate();

		std::cout << "\n--- Fight Over ---" << std::endl;

		if (clap.getHitPoints() > 0) {
			std::cout << clap.getName() << " wins." << std::endl;
		} else {
			std::cout << scav.getName() << " wins." << std::endl;
		}
	}
	return 0;
}
