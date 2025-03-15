#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

int main()
{
	try
	{
		Form form("Form", 1, 1);
		std::cout << form << std::endl;
		Bureaucrat John("John", 15);
		std::cout << John << std::endl;
		John.signForm(form);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
