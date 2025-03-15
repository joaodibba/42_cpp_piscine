#include "../includes/Form.hpp"

Form::Form() : _name(""), _signed(false), _gradeToSign(0), _gradeToExecute(0) {} // Default constructor is private thus cannot be called

Form::Form(std::string const name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	checkGrade(gradeToSign);
	checkGrade(gradeToExecute);
}

Form::Form(Form const &other) : _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {}

Form &Form::operator=(Form const &other)
{
	if (this != &other)
		_signed = other._signed;
	return *this;
}

Form::~Form() {}

std::string const &Form::getName() const
{
	return _name;
}

bool Form::getSigned() const
{
	return _signed;
}

int Form::getGradeToSign() const
{
	return _gradeToSign;
}

int Form::getGradeToExecute() const
{
	return _gradeToExecute;
}

void Form::beSigned()
{
	if (!_signed)
		_signed = true;
}

void Form::checkGrade(int grade) const
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

std::ostream &operator<<(std::ostream &out, Form const &form)
{
	out << "Form " << form.getName() << " is " << (form.getSigned() ? "" : "not ") << "signed, requires grade " << form.getGradeToSign() << " to sign, and grade " << form.getGradeToExecute() << " to execute";
	return out;
}
