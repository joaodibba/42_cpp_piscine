#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>
#include <cstdlib>

int main() {
    std::cout << "--- ScavTrap vs FragTrap Fight ---" << std::endl;
    {

        // Create one ScavTrap and one FragTrap instance
        ScavTrap scav("SC4V-TP");
        FragTrap frag("FR4G-TP");

        std::cout << "\n--- Initial Stats ---" << std::endl;

        std::cout << scav.getName() << " has " << scav.getHitPoints() << " hit points, "
                  << scav.getEnergyPoints() << " energy points and "
                  << scav.getAttackDamage() << " attack damage." << std::endl;
        std::cout << frag.getName() << " has " << frag.getHitPoints() << " hit points, "
                  << frag.getEnergyPoints() << " energy points and "
                  << frag.getAttackDamage() << " attack damage." << std::endl;

        std::cout << "\n--- Fight Begins ---" << std::endl;

        while (scav.getHitPoints() > 0 && frag.getHitPoints() > 0) {
            if (rand() % 2 == 0) {
                if (scav.getEnergyPoints() > 0) {
                    scav.attack(frag.getName());
                    frag.takeDamage(scav.getAttackDamage());
                }
            } else {
                if (frag.getEnergyPoints() > 0) {
                    frag.attack(scav.getName());
                    scav.takeDamage(frag.getAttackDamage());
                }
            }

            std::cout << "\n--- Current Stats ---" << std::endl;

            std::cout << scav.getName() << " has " << scav.getHitPoints() << " hit points, "
                      << scav.getEnergyPoints() << " energy points." << std::endl;
            std::cout << frag.getName() << " has " << frag.getHitPoints() << " hit points, "
                      << frag.getEnergyPoints() << " energy points." << std::endl;
        }

        scav.guardGate();

        std::cout << "\n--- Fight Over ---" << std::endl;

        if (scav.getHitPoints() > 0) {
            std::cout << scav.getName() << " wins." << std::endl;
        } else {
            std::cout << frag.getName() << " wins." << std::endl;
        }
    }
    return 0;
}
