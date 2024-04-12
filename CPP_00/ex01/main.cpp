#include "MyAwesomePhoneBook.hpp"

int	main()
{
	PhoneBook pb;
	std::string input;

	std::cout << "Welcome to the phonebook!" << std::endl;
	while (1){
		std::cout << "PhoneBook=>";
		std::getline(std::cin, input);
		if (std::cin.eof())
			break;
		if (input.empty())
			continue;
		if (input == "ADD")
			pb.addContact();
		else if (input == "SEARCH")
			pb.searchContact();
		else if (input == "EXIT")
			break;
		else
			std::cout << "Invalid option" << std::endl;
	}
	return (0);
}