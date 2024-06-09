#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("default") {}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other) : AForm(other), _target(other._target) {}


PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &other)
{
	if (this != &other)
		AForm::operator=(other);
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

std::string const &PresidentialPardonForm::getTarget() const
{
	return _target;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	(void)executor;
	if (!getSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > getGradeToExecute())
		throw AForm::GradeTooLowException();
	std::cout << _target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}
