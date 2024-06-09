#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		_grade = other._grade;
	return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string &Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::incrementGrade()
{
	if (_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
	return out;
}

void Bureaucrat::executeForm(AForm const & form)
{
	if (form.getSigned() == false)
		throw AForm::FormNotSignedException();
	if (_grade > form.getGradeToExecute())
		throw Bureaucrat::GradeTooLowException();
	form.execute(*this);
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}
void Bureaucrat::signForm(const AForm &form)
{
	if (_grade > form.getGradeToSign())
		throw Bureaucrat::GradeTooLowException();
	try {
		const_cast<AForm &>(form).beSigned(*this); // const_cast is used to remove the const qualifier from form
		std::cout << _name << " signs " << form.getName() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << _name << " cannot sign " << form.getName() << " because " << e.what() << std::endl;
	}
}