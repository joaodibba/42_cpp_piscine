#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include "Brain.hpp"
# include <iostream>
# include <string>

class AAnimal
{

protected:
	std::string _type;

public:
	AAnimal();
	AAnimal(const AAnimal &other);
	virtual ~AAnimal();
	AAnimal &operator=(const AAnimal &right);

	std::string getType() const;

	virtual void makeSound() const = 0;

};

#endif