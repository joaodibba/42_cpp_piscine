#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{

private:
	AForm();
	const std::string	_name;
	bool				_signed;
	const int			_gradeToSign;
	const int			_gradeToExecute;

public:
	AForm(const std::string name, int gradeToSign, int gradeToExecute);
	AForm(const AForm &other);
	AForm &operator=(const AForm &other);
	virtual ~AForm();

	const std::string &getName() const;
	bool getSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	void beSigned(const Bureaucrat &bureaucrat);
	void checkGrade(int grade) const;
	virtual void execute(Bureaucrat const &executor) const = 0;

	struct GradeTooHighException : public std::exception
	{
		virtual char *what() const throw();
	};

	struct GradeTooLowException : public std::exception
	{
		virtual char *what() const throw();
	};
	struct FormNotSignedException : public std::exception
	{
		virtual const char *what() const throw();
	};
	struct FormAlreadySignedException : public std::exception
	{
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &out, const AForm &aForm);

#endif