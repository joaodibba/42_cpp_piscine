#include "../includes/AAnimal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"

int main()
{
    // AAnimal test;
    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();
    delete j;//should not create a leak
    delete i;

    std::cout << "\n*********** My tests ***********\n" << std::endl;

    AAnimal *animals[10];
    
    int x = 0;
    for (x = 0; x < 5; x++)
        animals[x] = new Dog();
    for ( ; x < 10; x++)
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

    AAnimal *beast = new Dog();
    
    try 
    {
    	for (int x = 0; x < 101; x++)
        	beast->getBrain()->setIdea(x, "Thinks in the language of dogs...");

    	AAnimal *copy = new Dog(static_cast<Dog&>(*beast));

  		std::cout << std::endl;
        for (int x = 0; x < 101; x++)
            std::cout << copy->getBrain()->getIdea(x) << std::endl;
    	delete copy;
    } 
    catch(std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    delete beast;

    return 0;
}