#include "MyAwesomePhoneBook.hpp"

PhoneBook::PhoneBook() : lastContact(0)
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
	this->contacts[lastContact] = contact;
	lastContact++;
	if (lastContact > 7)
		lastContact = 0;
}

void	printContact(Contact contact)
{
	std::cout 
			<< std::right << std::setw(MAX_WIDTH) << formatStr(contact.getFirstName(), MAX_WIDTH)
			<< "|" << std::right << std::setw(MAX_WIDTH) << formatStr(contact.getLastName(), MAX_WIDTH)
			<< "|" << std::right << std::setw(MAX_WIDTH) << formatStr(contact.getNickName(), MAX_WIDTH)
	<< std::endl;
}

void	PhoneBook::printAllContacts()
{
	std::cout << "     index" << "|" << "First name" << "|" << " Last Name" << "|" << "  Nickname\n"
	<< "----------" << "+" << "----------" << "+" << "----------" << "+" << "----------" << std::endl;
	for (int i = 0; i < MAX_CONTACTS; i++)
	{
		std::stringstream indexStr;
		indexStr << i;
		std::cout << std::right << std::setw(MAX_WIDTH) << indexStr.str() << "|";
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
			std::stringstream indexStr;
			indexStr << index;
			std::cout
						<< "Index          : " << indexStr.str()
						<< "\nFirst Name     : " << contacts[index].getFirstName()
						<< "\nLast Name      : " << contacts[index].getLastName()
						<< "\nNick Name      : " << contacts[index].getNickName()
						<< "\nPhone Number   : " << contacts[index].getPhoneNumber()
						<< "\nDarkest Secret : " << contacts[index].getDarkestSecret() 
						<< std::endl;
		}
		else
			std::cout << "Contact not found" << std::endl;
	}
	else
		std::cout << "Invalid index" << std::endl;
}