#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

int main() 
{
	try {
		Bureaucrat John("John", 15);
		std::cout << John;
		for (int i = 0; i <= 15; i++) {
			John.incrementGrade();
			std::cout << John;
		}
	} catch (std::exception &e) {
		std::cout << "Exception caught while incrementing: " << e.what() << std::endl;
	}

	try {
		Bureaucrat Jane("Jane", 140);
		std::cout << Jane;
		for (int i = 0; i <= 15; i++) {
			Jane.decrementGrade();
			std::cout << Jane;
		}
	} catch (std::exception &e) {
		std::cout << "Exception caught while decrementing: " << e.what() << std::endl;
	}

	try {
		Bureaucrat edgeCaseHigh("Max", 1);
		edgeCaseHigh.incrementGrade();  // Should throw
	} catch (std::exception &e) {
		std::cout << "Edge case high: " << e.what() << std::endl;
	}

	try {
		Bureaucrat edgeCaseLow("Min", 150);
		edgeCaseLow.decrementGrade();  // Should throw
	} catch (std::exception &e) {
		std::cout << "Edge case low: " << e.what() << std::endl;
	}

	try {
		Form form("Form", 1, 1);
		std::cout 	<< "Form name: " << form.getName()
					<< "\nForm getSigned: " << (form.getSigned() ? "True" : "False")
					<< "\nForm getGradeToSign: " << form.getGradeToSign()
					<< "\nForm getGradeToExecute: " << form.getGradeToExecute()
					<< std::endl;
	} catch (std::exception &e) { 
		std::cout << "Exception caught while creating form: " << e.what() << std::endl;
	}

	try {
		Form form("Form", 0, 1);  // Should throw exception
	} catch (std::exception &e) {
		std::cout << "Exception caught while creating form: " << e.what() << std::endl;
	} 
	try {
		Form form("Form", 1, 151);  // Should throw exception
	} catch (std::exception &e) {
		std::cout << "Exception caught while creating form: " << e.what() << std::endl;
	}
}
