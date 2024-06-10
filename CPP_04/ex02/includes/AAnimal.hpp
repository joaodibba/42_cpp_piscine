#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>
# include "Brain.hpp"

class AAnimal
{
	protected:
		std::string type;
	public:
		AAnimal();
		AAnimal(std::string type);
		virtual ~AAnimal();
		AAnimal(const AAnimal &animal);
		AAnimal &operator=(const AAnimal &animal);
		std::string getType() const;
		
		virtual void makeSound() const; // TODO: this should be a pure virtual function
		virtual Brain *getBrain() const = 0;
};

#endif