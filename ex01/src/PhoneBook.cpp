#include "../includes/PhoneBook.hpp"

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
	if (i == 7)
		i = 0;
	std::cout << "Please, Add the first name of the contact" << std::endl;
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
		{
			this->_contacts[i].setFirstName(firstName);
			break ;
		}
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
	std::cout << "Please, Add the Darkest secret of the contact" << std::endl;
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

void	display(std::string s)
{
	if (s.size() > 10)
	{
		s = s.substr(0, 10);
		s[9] = '.';
	}
	std::cout << std::setw(10) << s << '|';
}

void PhoneBook::search() const
{
	int index;

	if (this->_contacts[0].getFirstName().empty())
	{
		std::cout << "The phonebook is empty" << std::endl << std::endl;
		return ;
	}
	for (int i = 0; i < 8; i++)
	{
		if (this->_contacts[i].getFirstName().empty())
			break ;
		std::cout << std::setw(10) << i << "|";
		display(this->_contacts[i].getFirstName());
		display(this->_contacts[i].getLastName());
		display(this->_contacts[i].getNickName());
		std::cout << std::endl;
	}
	std::cout << "Enter an index to have all the informations of the contact" << std::endl;
	std::cin >> index;
	if (index > 9 || index < 0)
	{
		std::cout << "Index out of range. Please enter an index between 0 and 7: ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return ;
	}
	if (!this->_contacts[index].getFirstName().empty())
	{
		std::cout << std::endl;
		std::cout << "Contact number " << index << std::endl;
		std::cout << "Name : " << this->_contacts[index].getFirstName() << std::endl;
		std::cout << "Last name : " << this->_contacts[index].getLastName() << std::endl;
		std::cout << "Nick name : " << this->_contacts[index].getNickName() << std::endl;
	}
	else
		std::cout << "Index " << index << " is not attributed yet" << std::endl;
	std::cout << std::endl;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
