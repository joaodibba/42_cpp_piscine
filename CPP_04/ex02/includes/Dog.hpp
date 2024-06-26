#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal
{

private:
	Brain *brain;

public:
	Dog();
	Dog(const Dog &other);
	virtual ~Dog();
	Dog &operator=(const Dog &right);

	virtual void makeSound() const;
	Brain *getBrain() const;
};

#endif