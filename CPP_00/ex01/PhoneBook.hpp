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

public:
	PhoneBook();
	void	addContact();
	void	searchContact();
	void	printAllContacts();
};

#endif