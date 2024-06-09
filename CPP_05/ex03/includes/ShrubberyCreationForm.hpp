#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <exception>
#include "AForm.hpp"
#include <fstream>


class ShrubberyCreationForm : public AForm
{
private:
	const std::string _target;
	ShrubberyCreationForm();
public:
	ShrubberyCreationForm(const std::string &target);
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
	~ShrubberyCreationForm();

	const std::string &getTarget() const;
	void execute(const Bureaucrat &executor) const;
	struct FileNotOpenedException : public std::exception
	{
		virtual const char *what() const throw();
	};
};

#endif