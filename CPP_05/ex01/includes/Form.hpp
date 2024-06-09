#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>

class Form{
private:
	Form();
	std::string const _name;
	bool _signed;
	int const _gradeToSign;
	int const _gradeToExecute;
public:
	Form(std::string const name, int gradeToSign, int gradeToExecute);
	Form(Form const &other);
	Form &operator=(Form const &other);
	~Form();

	std::string const &getName() const;
	bool getSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	void beSigned();
	void checkGrade(int grade) const;

	struct GradeTooHighException : public std::exception
	{
		virtual const char *what() const throw();
	};

	struct GradeTooLowException : public std::exception
	{
		virtual const char *what() const throw();
	};
};

#endif