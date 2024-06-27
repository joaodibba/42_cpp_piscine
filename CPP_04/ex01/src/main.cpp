#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"

int main() {
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;
    delete i;

    std::cout << "\n*********** My tests ***********\n" << std::endl;

    Animal* animals[10];


    int x = 0;
    for (x = 0; x < 5; x++)
        animals[x] = new Dog();
    for (; x < 10; x++)
        animals[x] = new Cat();
    for (int k = 0; k < 10; k++)
        animals[k]->makeSound();
    for (int k = 0; k < 10; k++)
        delete animals[k];

    std::cout << "\n***** Copy and assignment tests *****\n" << std::endl;

    Dog basic;
    {
        Dog tmp = basic;
    }

    std::cout << "\n*********** My tests ***********\n" << std::endl;

    Animal* beast = new Dog();

    try {
        for (int x = 0; x < 100; x++)
            beast->getBrain()->setIdea(x, "Thinks in the language of dogs...");
        std::cout << "Joao " << std::endl;
        Animal* copy = new Dog(static_cast<Dog&>(*beast));

        for (int x = 0; x < 100; x++)
            std::cout << copy->getBrain()->getIdea(x) << std::endl;
        delete copy;
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    delete beast;

    return (0);
}

// Tests from the subject
// int main()
// {
// 	const Animal* j = new Dog();
// 	const Animal* i = new Cat();
// 	delete j;//should not create a leak
// 	delete i;

// 	return 0;
// }