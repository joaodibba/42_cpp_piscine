#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"

int main()
{
	{
		std::cout << "\n----- Test1 ------" << std::endl;
		std::cout << "\n----- Animal ------" << std::endl;
		const Animal* meta = new Animal();
		std::cout << "\n----- Dog ------" << std::endl;
		const Animal* j = new Dog();
		std::cout << "\n----- Cat ------" << std::endl;
		const Animal* i = new Cat();

		std::cout << "\n----- Animal ------" << std::endl;
		std::cout << "Animal type: " << meta->getType() << "." << std::endl;
		meta->makeSound();

		std::cout << "\n----- Dog ------" << std::endl;
		std::cout << "Dog type: " << j->getType() << "." << std::endl;
		i->makeSound();

		std::cout << "\n----- Cat ------" << std::endl;
		std::cout << "Cat type: " << i->getType() << "." << std::endl;
		j->makeSound();

		std::cout << "\n---------------------" << std::endl;
		delete meta;
		delete j;
		delete i;
		std::cout << "\n----- Test1 End ------" << std::endl;
	}
	{
		std::cout << "\n----- Test2 ------" << std::endl;
		std::cout << "\n----- WrongAnimal ------" << std::endl;
		const WrongAnimal* wrongMeta = new WrongAnimal();
		std::cout << "\n----- WrongCat ------" << std::endl;
		const WrongAnimal* j2 = new WrongCat();

		std::cout << "\n----- WrongAnimal ------" << std::endl;
		std::cout << "WrongAnimal type: " << wrongMeta->getType() << "."<< std::endl;
		wrongMeta->makeSound();

		std::cout << "\n----- WrongCat ------" << std::endl;
		std::cout << "WrongCat type: " << j2->getType() << "." << std::endl;
		j2->makeSound();
		std::cout << "\n---------------------" << std::endl;

		delete wrongMeta;
		delete j2;
		std::cout << "\n----- Test2 End------" << std::endl;
	}
	return (0);
}

// Main from subject

// int main()
// {
// 	const Animal* meta = new Animal();
// 	const Animal* j = new Dog();
// 	const Animal* i = new Cat();
// 	std::cout << j->getType() << " " << std::endl;
// 	std::cout << i->getType() << " " << std::endl;
// 	i->makeSound(); //will output the cat sound!
// 	j->makeSound();
// 	meta->makeSound();

// return 0;
// }

// Wrong main

// int main()
// {
// 	const WrongAnimal* meta = new WrongAnimal();
// 	const WrongAnimal* i = new WrongCat();
// 	std::cout << i->getType() << " " << std::endl;
// 	i->makeSound(); //will output the cat sound!
// 	meta->makeSound();

// return 0;
// }