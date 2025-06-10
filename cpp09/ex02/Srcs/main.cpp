#include "PmergeMe.hpp"
#include <iostream>
#include <string>

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << std::endl << "Wrong format" << std::endl;
		return 1;
	}

	std::string args[argc - 1];
	for (int i = 0; i < argc - 1; i++)
		args[i] = argv[i + 1];

	try
	{
		PmergeMe sort(args, argc - 1);
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
		return 1;
	}

	return 0;
}
