#include "ClapTrap.hpp"
#include <iostream>

int main() {
    std::cout << "--- ClapTrap Fight ---" << std::endl;
    {
        // Create two ClapTrap instances with zero attack damage
        ClapTrap clap1("CL4P-TP1");
        ClapTrap clap2("CL4P-TP2");

        std::cout << "\n--- Initial Stats ---" << std::endl;

        std::cout << clap1.getName() << " has " << clap1.getHitPoints() << " hit points, "
                  << clap1.getEnergyPoints() << " energy points and " 
                  << clap1.getAttackDamage() << " attack damage." << std::endl;
        std::cout << clap2.getName() << " has " << clap2.getHitPoints() << " hit points, "
                  << clap2.getEnergyPoints() << " energy points and "
                  << clap2.getAttackDamage() << " attack damage." << std::endl;

        std::cout << "\n--- Fight Begins ---" << std::endl;

        clap1.attack(clap2.getName());
        clap2.takeDamage(clap1.getAttackDamage());

        clap2.attack(clap1.getName());
        clap1.takeDamage(clap2.getAttackDamage());

        std::cout << clap1.getName() << " has " << clap1.getHitPoints() << " hit points, "
                  << clap1.getEnergyPoints() << " energy points." << std::endl;
        std::cout << clap2.getName() << " has " << clap2.getHitPoints() << " hit points, "
                  << clap2.getEnergyPoints() << " energy points." << std::endl;
    }
    std::cout << "\n--- Fight Over ---" << std::endl;
    return 0;
}
