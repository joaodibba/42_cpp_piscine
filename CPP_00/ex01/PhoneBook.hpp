#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include "MyAwesomePhoneBook.hpp"
# include <string>
# include <sstream>
# include <iomanip>

class PhoneBook{

private:
	Contact contacts[MAX_CONTACTS];
	int		lastContact;

	std::string addFirstName();
	std::string addLastName();
	std::string addNickName();
	std::string addPhoneNumber();
	std::string addDarkestSecret();
	void		printAllContacts();

public:
	PhoneBook();
	void	addContact();
	void	searchContact();
};

#endif