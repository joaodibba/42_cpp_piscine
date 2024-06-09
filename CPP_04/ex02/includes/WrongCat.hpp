#ifndef WRONG_CAT_HPP
# define WRONG_CAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(std::string type);
		WrongCat(const WrongCat &wrongCat);
		WrongCat &operator=(const WrongCat &wrongCat);
		virtual ~WrongCat();

		void makeSound() const;
};

#endif