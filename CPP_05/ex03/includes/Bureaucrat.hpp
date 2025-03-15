#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
private:
	Bureaucrat();
	const std::string	_name;
	int					_grade;

public:
	Bureaucrat(const std::string name, int grade);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(Bureaucrat const &other);
	~Bureaucrat();

	const std::string &getName() const;
	int getGrade() const;
	void incrementGrade();
	void decrementGrade();
	void signForm(const AForm &form);
	void executeForm( AForm const &form);

	struct GradeTooHighException : public std::exception
	{
		virtual virtual const char *what() const throw();
	};

	struct GradeTooLowException : public std::exception
	{
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat);

#endif