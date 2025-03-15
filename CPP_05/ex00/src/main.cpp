#include "../includes/Bureaucrat.hpp"

int main()
{
	try
	{
		std::cout << "Test 00: Should not throw exception" << std::endl;
		Bureaucrat John("John", 15);
		std::cout << John;
		for (int i = 0; i < 14; i++)
		{
			John.incrementGrade();
			std::cout << John;
		}
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught while incrementing: " << e.what() << std::endl;
	}
	catch (...)
	{
		std::cerr << "Caught an unknown exception!" << std::endl;
	}

	try
	{
		std::cout << "Test 01: Should throw exception" << std::endl;
		Bureaucrat Jane("Jane", 140);
		std::cout << Jane;
		for (int i = 0; i <= 15; i++)
		{
			Jane.decrementGrade();
			std::cout << Jane;
		}
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught while decrementing: " << e.what() << std::endl;
	}
	catch (...)
	{
		std::cerr << "Caught an unknown exception!" << std::endl;
	}

	try
	{
		std::cout << "Test 02: Should throw exception" << std::endl;
		Bureaucrat edgeCaseHigh("Max", 1);
		std::cout << edgeCaseHigh;
		edgeCaseHigh.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << "Edge case high: " << e.what() << std::endl;
	}
	catch (...)
	{
		std::cerr << "Caught an unknown exception!" << std::endl;
	}

	try
	{
		std::cout << "Test 03: Should throw exception" << std::endl;
		Bureaucrat edgeCaseLow("Min", 150);
		std::cout << edgeCaseLow;
		edgeCaseLow.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << "Edge case low: " << e.what() << std::endl;
	}
	catch (...)
	{
		std::cerr << "Caught an unknown exception!" << std::endl;
	}

	return 0;
}
