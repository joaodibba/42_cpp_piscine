#ifndef WRONG_CAT_HPP
# define WRONG_CAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{

public:
	WrongCat();
	WrongCat(const WrongCat &other);
	virtual ~WrongCat();
	WrongCat &operator=(const WrongCat &right);

	void makeSound() const;

};

#endif