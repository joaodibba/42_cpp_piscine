#include "../includes/Bureaucrat.hpp"

int main()
{
	// Test with incrementing
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

	// Test with decrementing
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

	// Testing edge cases
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

	return 0;
}
