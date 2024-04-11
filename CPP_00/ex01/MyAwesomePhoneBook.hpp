#ifndef MY_AWESOME_PHONE_BOOK_HPP
# define MY_AWESOME_PHONE_BOOK_HPP

# define MAX_CONTACTS 8
# define MAX_WIDTH 10
# define SLEEP_TIME 900000

# include <iostream>
# include <string>
# include <unistd.h>
# include "PhoneBook.hpp"
# include "Contact.hpp"

std::string	formatStr(std::string str, unsigned int width);
bool		strIsAllNum(const std::string str);
bool		strContainsTab(const std::string &str);

#endif