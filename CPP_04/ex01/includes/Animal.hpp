#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include "Brain.hpp"
# include <iostream>
# include <string>

class Animal
{

protected:
	std::string _type;

public:
	Animal();
	Animal(const Animal &other);
	virtual ~Animal();
	Animal &operator=(const Animal &right);

	std::string getType() const;

	virtual void makeSound() const = 0;
	virtual Brain *getBrain() const = 0;

};

#endif