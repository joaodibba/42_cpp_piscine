#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

# define MAX_IDEAS 100

class Brain
{
	private:
		std::string ideas[MAX_IDEAS];
	public:
		Brain();
		Brain(const Brain &brain);
		Brain &operator=(const Brain &brain);
		~Brain();
		std::string getIdea(int index) const;
		void setIdea(int index, std::string idea);
};

#endif