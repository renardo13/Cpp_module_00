#include "../includes/PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phoneBook;
	int			i;

	std::string line;
	i = 0;
	std::cout << "Welcome to the phoneBook" << std::endl;
	std::cout << "Please, Type ADD, SEARCH or EXIT" << std::endl;
	while (std::getline(std::cin, line))
	{
		if (line == "ADD")
		{
			phoneBook.add(i);
			i++;
		}
		else if (line == "SEARCH")
		{
			phoneBook.search();
		}
		else if (line == "EXIT")
			return (0);
		else
			std::cout << "Command is not valid" << std::endl;
		std::cout << "Please, Type ADD, SEARCH or EXIT" << std::endl;
	}
}
