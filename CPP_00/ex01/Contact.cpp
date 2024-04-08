#include "MyAwesomePhoneBook.hpp"

Contact::Contact()
{
}
// set
void	Contact::setFirstName(std::string FirstName)
{
	this->FirstName = FirstName;
}

void	Contact::setLastName(std::string LastName)
{
	this->LastName = LastName;
}

void	Contact::setNickName(std::string NickName)
{
	this->NickName = NickName;
}

void	Contact::setPhoneNumber(std::string PhoneNumber)
{
	this->PhoneNumber = PhoneNumber;
}

void	Contact::setDarkestSecret(std::string DarkestSecret)
{
	this->DarkestSecret = DarkestSecret;
}

// get
const std::string	&Contact::getFirstName() const
{
	return (this->FirstName);
}

const std::string	&Contact::getLastName() const
{
	return (this->LastName);
}

const std::string	&Contact::getNickName() const
{
	return (this->NickName);
}

const std::string	&Contact::getPhoneNumber() const
{
	return (this->PhoneNumber);
}

const std::string	&Contact::getDarkestSecret() const
{
	return (this->DarkestSecret);
}