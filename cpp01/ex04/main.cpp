#include <fstream>
#include <iostream>
#include <string>

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "The program takes in argument a filename and 2 strings" << std::endl;
		return (1);
	}
	std::string filename = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];
	std::ifstream file(filename);
	if (!file)
	{
		std::cerr << "Impossible to load the file." << std::endl;
		return (1);
	}
	std::string outputFilename = filename + ".replace";
	std::ofstream outputFile(outputFilename);
	if (!outputFile)
	{
		std::cerr << "Impossible to create the new file." << std::endl;
		file.close();
		return (0);
	}
	std::string line;
	while (std::getline(file, line))
	{
		size_t index = line.find(s1);
		while(index != std::string::npos) // si les valeurs sont differentes ca veut dire au une sous chaine a ete trouvee.
		{
			line.replace(index, s1.length(), s2);
			index = line.find(s1, index + s2.length());
		}
		outputFile << line << std::endl;
	}
}
