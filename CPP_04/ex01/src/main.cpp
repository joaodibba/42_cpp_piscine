#include "../includes/AAnimal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"

int main() {
    std::cout << "\n***** Initial Tests *****\n" << std::endl;

    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;
    delete i;

    std::cout << "\n***** Array of Animals Tests *****\n" << std::endl;

    Animal* animals[10];

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

    std::cout << "\n***** Deep Copy Tests *****\n" << std::endl;

    Animal* beast = new Dog();
    Dog copyDog;

    try {
        for (int x = 0; x < 10; x++) {
            beast->getBrain()->setIdea(x, "This is a test idea");
        }
        
        std::cout << "Copying beast to copyDog using assignment operator" << std::endl;
        copyDog = static_cast<Dog&>(*beast); // Assignment operator test

        for (int x = 0; x < 10; x++) {
            std::cout << copyDog.getBrain()->getIdea(x) << std::endl;
        }
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    delete beast;

    std::cout << "\n***** End of Tests *****\n" << std::endl;

    return 0;
}

// // Tests from the subject
// int main()
// {
// 	const Animal* j = new Dog();
// 	const Animal* i = new Cat();
// 	delete j;//should not create a leak
// 	delete i;

// 	return 0;
// }