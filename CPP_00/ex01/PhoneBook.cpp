#include "MyAwesomePhoneBook.hpp"

PhoneBook::PhoneBook() : lastContact(0)
{
}

std::string PhoneBook::addFirstName()
{
	std::string input;
	std::cout << "Enter first name: ";
	std::getline(std::cin >> std::ws, input);
	if (std::cin.eof() || input.empty())
	{
		std::cout << "Input not valid: " << "First Name can't be empty" << std::endl;
		return "";
	}
	if (strContainsTab(input))
	{
		std::cout << "Input not valid: " << "First Name can't have Tabs" << std::endl;
		return "";
	}
	return input;
}

std::string PhoneBook::addLastName()
{
	std::string input;
	std::cout << "Enter last name: ";
	std::getline(std::cin >> std::ws, input);
	if (std::cin.eof() || input.empty())
	{
		std::cout << "Input not valid: " << "Last Name can't be empty" << std::endl;
		return "";
	}
	if (strContainsTab(input))
	{
		std::cout << "Input not valid: " << "Last Name can't have Tabs" << std::endl;
		return "";
	}
	return input;
}

std::string PhoneBook::addNickName()
{
	std::string input;
	std::cout << "Enter nickname: ";
	std::getline(std::cin >> std::ws, input);
	if (std::cin.eof() || input.empty())
	{
		std::cout << "Input not valid: " << "Nickname can't be empty" << std::endl;
		return "";
	}
	if (strContainsTab(input))
	{
		std::cout << "Input not valid: " << "Nickname can't have Tabs" << std::endl;
		return "";
	}
	return input;
}

std::string PhoneBook::addPhoneNumber()
{
	std::string input;
	std::cout << "Enter phone number: ";
	std::getline(std::cin >> std::ws, input);
	if (std::cin.eof() || input.empty())
	{
		std::cout << "Input not valid: " << "Phone Number can't be empty" << std::endl;
		return "";
	}
	if (!strIsAllNum(input))
	{
		std::cout << "Input not valid: " << "Phone Number must contain only digits" << std::endl;
		return "";
	}
	if (strContainsTab(input))
	{
		std::cout << "Input not valid: " << "Phone Number can't have Tabs" << std::endl;
		return "";
	}
	return input;
}

std::string PhoneBook::addDarkestSecret()
{
	std::string input;
	std::cout << "Enter darkest secret: ";
	std::getline(std::cin >> std::ws, input);
	if (std::cin.eof() || input.empty())
	{
		std::cout << "Input not valid: " << "Darkest Secret can't be empty" << std::endl;
		return "";
	}
	if (strContainsTab(input))
	{
		std::cout << "Input not valid: " << "Darkest Secret can't have Tabs" << std::endl;
		return "";
	}
	return input;
}

void PhoneBook::addContact()
{
	std::string input;
	Contact contact;

	input = addFirstName();
	if (input.empty())
		return;
	contact.setFirstName(input);
	input = addLastName();
	if (input.empty())
		return;
	contact.setLastName(input);
	input = addNickName();
	if (input.empty())
		return;
	contact.setNickName(input);
	input = addPhoneNumber();
	if (input.empty())
		return;
	contact.setPhoneNumber(input);
	input = addDarkestSecret();
	if (input.empty())
		return;
	contact.setDarkestSecret(input);

	this->contacts[lastContact] = contact;
	if (++lastContact == MAX_CONTACTS)
		lastContact = 0;
}

void	printContact(Contact contact)
{
	std::cout 
			<< std::right << std::setw(MAX_WIDTH) << formatStr(contact.getFirstName(), MAX_WIDTH) << "|" 
			<< std::right << std::setw(MAX_WIDTH) << formatStr(contact.getLastName(), MAX_WIDTH) << "|"
			<< std::right << std::setw(MAX_WIDTH) << formatStr(contact.getNickName(), MAX_WIDTH) << std::endl;
}

void	PhoneBook::printAllContacts()
{
	if (this->contacts[0].getFirstName().empty())
		return ;
	std::cout 
			<< std::right << std::setw(MAX_WIDTH) << "index" << "|"
			<< std::right << std::setw(MAX_WIDTH) << "First name" << "|"
			<< std::right << std::setw(MAX_WIDTH) << "Last Name" << "|" 
			<< std::right << std::setw(MAX_WIDTH) << "Nickname\n"
			<< "----------" << "+" << "----------" << "+" 
			<< "----------" << "+" << "----------" << std::endl;
	for (int i = 0; i < MAX_CONTACTS; i++)
	{
		if (!this->contacts[i].getFirstName().empty())
		{
			std::stringstream indexStr;
			indexStr << i;
			std::cout << std::right << std::setw(MAX_WIDTH) << indexStr.str() << '|';
			printContact(this->contacts[i]);
		}
	}
}

void	PhoneBook::searchContact()
{
	if (this->contacts[0].getFirstName().empty())
	{
		std::cout << "PhoneBook empty :(" << std::endl;
		return ;
	}
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