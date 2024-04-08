#include "MyAwesomePhoneBook.hpp"

PhoneBook::PhoneBook()
{
}

void	PhoneBook::addContact()
{
	std::string input;
	Contact contact;

	std::cout << "Enter first name: ";
	std::getline(std::cin, input);
	if (std::cin.eof() || input.empty())
	{
		std::cout << "Expected a value: First Name can't be empty" << std::endl;
		return ;
	}
	contact.setFirstName(input);
	std::cout << "Enter last name: ";
	std::getline(std::cin, input);
	if (std::cin.eof() || input.empty())
	{
		std::cout << "Expected a value: Last Name can't be empty" << std::endl;
		return ;
	}
	contact.setLastName(input);
	std::cout << "Enter nickname: ";
	std::getline(std::cin, input);
	if (std::cin.eof() || input.empty())
	{
		std::cout << "Expected a value: Nickname can't be empty" << std::endl;
		return ;
	}
	contact.setNickName(input);
	std::cout << "Enter phone number: ";
	std::getline(std::cin, input);
	if (std::cin.eof() || input.empty())
	{
		std::cout << "Expected a value: Phone Number can't be empty" << std::endl;
		return ;
	}
	if (!strIsAllNum(input))
	{
		std::cout << "Error: Phone Number must contain only digits" << std::endl;
		return ;

	}
	contact.setPhoneNumber(input);
	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, input);
	if (std::cin.eof() || input.empty())
	{
		std::cout << "Expected a value: Darkest Secret can't be empty" << std::endl;
		return ;
	}
	contact.setDarkestSecret(input);
	for (int i = 0; i < MAX_CONTACTS; i++)
	{
		if (this->contacts[i].getFirstName().empty())
		{
			this->contacts[i] = contact;
			break;
		}
	}
}

// IS this replacing the 8th?

void	printContact(Contact contact)
{
	std::cout << formatStr(contact.getFirstName(), MAX_WIDTH) << "|" << formatStr(contact.getLastName(), MAX_WIDTH) << "|" << formatStr(contact.getNickName(), MAX_WIDTH) << std::endl;
}

void	PhoneBook::printAllContacts()
{
	std::cout << "     index" << "|" << "First name" << "|" << " Last Name" << "|" << "  Nickname" << std::endl;
	std::cout << "----------" << "+" << "----------" << "+" << "----------" << "+" << "----------" << std::endl;
	for (int i = 0; i < MAX_CONTACTS; i++)
	{
		std::cout << formatStr(std::to_string(i), MAX_WIDTH) << "|";
		printContact(this->contacts[i]);
	}
}

void	PhoneBook::searchContact()
{
	printAllContacts();
	std::string input;
	std::cout << "Enter index: ";
	std::getline(std::cin, input);
	if (input.length() == 1 && input[0] >= '0' && input[0] <= '7')
	{
		int index = input[0] - '0';
		if (!this->contacts[index].getFirstName().empty())
		{
			std::cout << "Index          : " << std::to_string(index) << std::endl;
			std::cout << "First Name     : " << contacts[index].getFirstName() << std::endl;
			std::cout << "Last Name      : " << contacts[index].getLastName() << std::endl;
			std::cout << "Nick Name      : " << contacts[index].getNickName() << std::endl;
			std::cout << "Phone Number   : " << contacts[index].getPhoneNumber() << std::endl;
			std::cout << "Darkest Secret : " << contacts[index].getDarkestSecret() << std::endl;
		}
		else
			std::cout << "Contact not found" << std::endl;
	}
	else
		std::cout << "Invalid index" << std::endl;
}