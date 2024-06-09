#include "../includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other) : AForm(other), _target(other._target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other)
{
	if (this != &other)
		AForm::operator=(other);
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

std::string const &ShrubberyCreationForm::getTarget() const
{
	return _target;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	(void)executor;
	std::string filename = _target + "_shrubbery";
	std::ofstream file(filename.c_str());
	if (!file.is_open())
		throw FileNotOpenedException();
	file \
	<< "\0         # #### ####         " \
	<< "\n       ### \\/#|### |/####    " \
	<< "\n      ##\\#/ \\||/##/_/##/_#  " \
	<< "\n    ###  \\###|/ \\ # ###    " \
	<< "\n  ##_/_#/_/## | #/###_/_#### " \
	<< "\n ## #### # \\#| /  #### ##/##" \
	<< "\n  __#_--###`  |{,###---###-~ " \
	<< "\n            \\ }{             " \
	<< "\n             }}{             " \
	<< "\n             }}{             " \
	<< "\n             {{}             " \
	<< "\n       , -=-~{ .-^- _        " \
	<< "\n             `}              " \
	<< "\n              {              " 
	<< std::flush;
	file.close();
}

const char *ShrubberyCreationForm::FileNotOpenedException::what() const throw()
{
	return "FileNotOpenedException: file could not be opened.";
}