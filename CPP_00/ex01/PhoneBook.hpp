#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include "MyAwesomePhoneBook.hpp"

class PhoneBook{

private:
	Contact contacts[MAX_CONTACTS];

public:
	PhoneBook();
	void	addContact();
	void	searchContact();
	void	printAllContacts();
};

#endif