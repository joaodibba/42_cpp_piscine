#include "MyAwesomePhoneBook.hpp"

int	main()
{
	PhoneBook pb;
	std::string input;

	std::cout << "Welcome to the phonebook!" << std::flush;
	usleep(SLEEP_TIME / 1.6);
	while (1){
		std::cout << "\x1b[2K\x1b[1G" << "PhoneBook=>";
		std::getline(std::cin, input);
		if (std::cin.eof() || input.empty())
			break;
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