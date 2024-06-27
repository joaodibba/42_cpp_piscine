#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal
{

private:
	Brain *brain;

public:
	Cat();
	Cat(const Cat &other);
	virtual ~Cat();
	Cat &operator=(const Cat &right);

	virtual void makeSound() const;
	virtual Brain *getBrain() const;

};

#endif