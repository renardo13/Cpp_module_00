#include "../includes/Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	if(N <= 0)
		std::cout << "The horde must have at least one zombie" << std::endl;
	Zombie *horde = new Zombie[N];
	for (int i = 0; i < N; i++)
		horde[i].setName(name);
 	return(horde);
}
