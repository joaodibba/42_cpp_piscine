#include "../includes/AAnimal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"

int main() {
    std::cout << "\n***** Initial Tests *****\n" << std::endl;

    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();
    delete j;
    delete i;

    std::cout << "\n***** Array of Animals Tests *****\n" << std::endl;

    AAnimal* animals[10];

    for (int x = 0; x < 5; x++) {
        animals[x] = new Dog();
    }
    for (int x = 5; x < 10; x++) {
        animals[x] = new Cat();
    }

    for (int k = 0; k < 10; k++) {
        animals[k]->makeSound();
    }

    for (int k = 0; k < 10; k++) {
        delete animals[k];
    }

    std::cout << "\n***** Copy and Assignment Tests *****\n" << std::endl;

    Dog basic;
    {
        Dog tmp = basic; // Copy constructor test
    }

    std::cout << "\n***** End of Tests *****\n" << std::endl;

    return 0;
}
