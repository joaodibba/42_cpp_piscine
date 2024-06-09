#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <exception>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	const std::string _target;
	PresidentialPardonForm();
public:
	PresidentialPardonForm(const std::string &target);
	PresidentialPardonForm(const PresidentialPardonForm &other);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
	~PresidentialPardonForm();

	const std::string &getTarget() const;
	void execute(Bureaucrat const &executor) const;
};

#endif