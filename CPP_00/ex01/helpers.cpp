#include "MyAwesomePhoneBook.hpp"

std::string	formatStr(std::string str, unsigned int maxWidth)
{
	std::string	formattedField = str;

	if (str.length() > maxWidth)
	{
		formattedField = str.substr(0, maxWidth - 1);
		formattedField += ".";
	}
	return (formattedField);
}

bool strIsAllNum(const std::string str)
{
	for (size_t i = 0; i < str.length(); i++){
		if (!isdigit(str[i]))
			return (false);
	}
	return (true);
}

bool strContainsTab(const std::string &str)
{
	for (size_t i = 0; i < str.length(); i++){
		if (str[i] == '\t')
			return (true);
	}
    return (false);
}