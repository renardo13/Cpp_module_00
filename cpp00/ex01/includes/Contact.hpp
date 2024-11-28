#ifndef CONTACT_HPP

#define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <limits>

class Contact
{
	private:
		std::string firstName;
   		std::string lastName;
    	std::string nickName;
    	std::string phoneNumber;
    	std::string darkestSecret;

	public:
		Contact();
		~Contact();
		void setFirstName(const std::string s);
		void setLastName(const std::string s);
		void setNickName(const std::string s);
		void setDarkestSecret(const std::string s);
		void setPhoneNumber(const std::string s);

		std::string getFirstName(void) const;
		std::string getLastName(void) const;
		std::string getNickName(void) const;
		std::string getDarkestSecret(void) const;
		std::string getPhoneNumber(void) const;
};

#endif