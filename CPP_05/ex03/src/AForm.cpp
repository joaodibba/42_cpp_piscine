#include "../includes/AForm.hpp"

AForm::AForm() : _name(""), _signed(false), _gradeToSign(1), _gradeToExecute(1) {}

AForm::AForm(const std::string name, int gradeToSign, int gradeToExecute) :
	_name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) 
{
	checkGrade(gradeToSign);
	checkGrade(gradeToExecute);
}

AForm::AForm(const AForm &other) : 
	_name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
		_signed = other._signed;
	return *this;
}

AForm::~AForm() {}

std::string const &AForm::getName() const 
{
	return _name;
}

bool AForm::getSigned() const 
{
	return _signed;
}

int AForm::getGradeToSign() const 
{
	return _gradeToSign;
}

int AForm::getGradeToExecute() const 
{
	return _gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw AForm::GradeTooLowException();
	if (_signed)
		throw AForm::FormAlreadySignedException();
	_signed = true;
}

void AForm::checkGrade(int grade) const
{
	if (grade < 1)
		throw AForm::GradeTooHighException();
	if (grade > 150)
		throw AForm::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &out, const AForm &aForm)
{
	out << aForm.getName() << " form is " << (aForm.getSigned() ? "" : "not ") << "signed." << std::endl;
	out << "Grade to sign: " << aForm.getGradeToSign() << std::endl;
	out << "Grade to execute: " << aForm.getGradeToExecute() << std::endl;
	return out;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return "Form is not signed";
}

const char *AForm::FormAlreadySignedException::what() const throw()
{
	return "Form is already signed";
}