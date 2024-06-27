#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

# include <iostream>
# include <string>

class WrongAnimal
{

protected:
	std::string _type;

public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal &other);
	virtual ~WrongAnimal();
	WrongAnimal &operator=(const WrongAnimal &right);

	std::string getType() const;
	
	void makeSound() const;		
};

#endif