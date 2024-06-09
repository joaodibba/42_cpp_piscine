#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/Bureaucrat.hpp"

int main()
{
	try {
		Bureaucrat b1("Bureaucrat 1", 1);
		Bureaucrat b2("Bureaucrat 2", 150);
		ShrubberyCreationForm scf("ShrubberyCreationForm");
		RobotomyRequestForm rrf("RobotomyRequestForm");
		PresidentialPardonForm ppf("PresidentialPardonForm");

		std::cout << b1 << std::endl;
		std::cout << b2 << std::endl;
		std::cout << scf << std::endl;
		std::cout << rrf << std::endl;
		std::cout << ppf << std::endl;

		b1.signForm(scf);
		b1.signForm(rrf);
		b1.signForm(ppf);

		b1.executeForm(scf);
		b1.executeForm(rrf);
		b1.executeForm(ppf);

		b2.signForm(scf);
		b2.signForm(rrf);
		b2.signForm(ppf);

		b2.executeForm(scf);
		b2.executeForm(rrf);
		b2.executeForm(ppf);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}