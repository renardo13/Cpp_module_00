#include "Contact.hpp"

Contact::Contact(void)
{

}

Contact::~Contact(void)
{
	
}

void Contact::setFirstName(const std::string str)
{
	this->firstName = str;
}
void Contact::setNickName(const std::string str)
{
	this->nickName = str;
}
void Contact::setLastName(const std::string str)
{
	this->lastName = str;
}
void Contact::setPhoneNumber(const std::string str)
{
	this->darkestSecret = str;
}
void Contact::setDarkestSecret(const std::string str)
{
	this->phoneNumber = str;
}

std::string Contact::getFirstName() const
{
	return (this->firstName);
}
std::string Contact::getNickName() const
{
	return (this->nickName);
}
std::string Contact::getLastName() const
{
	return (this->lastName);
}
std::string Contact::getPhoneNumber() const
{
	return (this->darkestSecret);
}
std::string Contact::getDarkestSecret() const
{
	return (this->phoneNumber);
}
