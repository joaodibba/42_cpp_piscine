#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{

private:
	Brain *brain;

public:
	Dog();
	Dog(const Dog &other);
	virtual ~Dog();
	Dog &operator=(const Dog &right);

	virtual void makeSound() const;
	virtual Brain *getBrain() const;
};

#endif