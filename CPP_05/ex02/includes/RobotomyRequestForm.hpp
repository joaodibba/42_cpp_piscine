#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <exception>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
	std::string _target;
	RobotomyRequestForm();
public:
	RobotomyRequestForm(std::string const &target);
	RobotomyRequestForm(RobotomyRequestForm const &other);
	RobotomyRequestForm &operator=(RobotomyRequestForm const &other);
	~RobotomyRequestForm();

	std::string const &getTarget() const;
	void execute(Bureaucrat const &executor) const;
};

#endif