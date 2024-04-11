#ifndef CONTACT_HPP
# define CONTACT_HPP

class Contact{

private:
	std::string FirstName, LastName, NickName, PhoneNumber, DarkestSecret;

public:
	Contact();
	void	setFirstName(std::string FirstName);
	void	setLastName(std::string LastName);
	void	setNickName(std::string NickName);
	void	setPhoneNumber(std::string PhoneNumber);
	void	setDarkestSecret(std::string DarkestSecret);

	const std::string	&getFirstName() const;
	const std::string	&getLastName() const;
	const std::string	&getNickName() const;
	const std::string	&getPhoneNumber() const;
	const std::string	&getDarkestSecret() const;
};

#endif