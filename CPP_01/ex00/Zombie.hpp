#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

class Zombie {
public:
    Zombie();
    Zombie(std::string newName);

    void zombieActivity(void);

    ~Zombie(void);

private:
    std::string name; // Make sure this is a string
};
Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif