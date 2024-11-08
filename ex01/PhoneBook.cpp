#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
}

PhoneBook::~PhoneBook(void)
{
}

int	strIsPrint(std::string s)
{
	for (int i = 0; s[i]; i++)
	{
		if (!isprint(s[i]))
			return (0);
	}
	return (1);
}

int	strIsAlpha(std::string s)
{
	for (int i = 0; s[i]; i++)
	{
		if (!isalpha(s[i]))
			return (0);
	}
	return (1);
}

int	strIsDigit(std::string s)
{
	for (int i = 0; s[i]; i++)
	{
		if (!isdigit(s[i]))
			return (0);
	}
	return (1);
}

int PhoneBook::add(int i)
{
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkestSecret;
	std::cout << "Please, Add the first name of the contact" << std::endl;
	if (i == 7)
		i = 0;
	while (true)
	{
		getline(std::cin, firstName);
		if (firstName.empty() || !strIsAlpha(firstName)
			|| !strIsPrint(firstName))
		{
			std::cout << "First Name should not be empty and have only letters and printable caracters" << std::endl;
			std::cout << "please, try again:" << std::endl;
		}
		else
			break ;
	}
	std::cout << "Please, Add the last name of the contact" << std::endl;
	while (true)
	{
		getline(std::cin, lastName);
		if (lastName.empty() || !strIsAlpha(lastName) || !strIsPrint(lastName))
		{
			std::cout << "Last Name should not be empty and have only letters and printable caracters" << std::endl;
			std::cout << "please, try again:" << std::endl;
		}
		else
		{
			this->_contacts[i].setLastName(lastName);
			break ;
		}
	}
	std::cout << "Please, Add the nick name of the contact" << std::endl;
	while (true)
	{
		getline(std::cin, nickName);
		if (nickName.empty() || !strIsAlpha(nickName) || !strIsPrint(nickName))
		{
			std::cout << "Last Name should not be empty and have only letters and printable caracters" << std::endl;
			std::cout << "please, try again:" << std::endl;
		}
		else
		{
			this->_contacts[i].setNickName(nickName);
			break ;
		}
	}
	std::cout << "Please, Add the Phone number of the contact" << std::endl;
	while (true)
	{
		getline(std::cin, phoneNumber);
		if (phoneNumber.empty() || !strIsDigit(phoneNumber)
			|| !strIsPrint(phoneNumber))
		{
			std::cout << "Phone number should not be empty and have only digits and printable caracters" << std::endl;
			std::cout << "please, try again:" << std::endl;
		}
		else
		{
			this->_contacts[i].setPhoneNumber(phoneNumber);
			break ;
		}
	}
	while (true)
	{
		getline(std::cin, darkestSecret);
		if (darkestSecret.empty() || !strIsPrint(darkestSecret))
		{
			std::cout << "the darkest secret should not be empty and have only printable caracters" << std::endl;
			std::cout << "please, try again:" << std::endl;
		}
		else
		{
			this->_contacts[i].setDarkestSecret(darkestSecret);
			break ;
		}
	}
	return (0);
}

void PhoneBook::search() const
{
	// std::cout << "The nick name" << std::endl;
	// getline(std::cin, firstName);
	// std::cout << "First name accepted: " << firstName << std::endl;
	// else (this->_contacts[i].setFirstName(firstName));
}
