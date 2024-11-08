#ifndef PHONEBOOK_HPP

#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	private: 
			Contact _contacts[8];
	public:
			PhoneBook(void);
			~PhoneBook(void);
			int add(int i);
			void search(void) const;
};

#endif