#include "MyAwesomePhoneBook.hpp"

std::string	formatStr(std::string str, unsigned int maxWidth)
{
	std::string	formattedField;	

	if (str.length() == maxWidth)
		formattedField = str;
	else if (str.length() > maxWidth)
	{
		formattedField = str.substr(0, maxWidth - 1);
		formattedField += ".";
	}
	else
	{
		formattedField = str;
		formattedField.insert(0, maxWidth - formattedField.length(), ' ');
	}
	return (formattedField);
}

bool strIsAllNum(std::string str)
{
	for (size_t i = 0; i < str.length(); i++) 
	{
		if (!isdigit(str[i]))
			return (false);
	}
	return (true);
}