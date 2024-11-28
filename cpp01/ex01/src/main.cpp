#include"../includes/Zombie.hpp"

int main (void)
{
	Zombie *Horde;

	Horde = zombieHorde(10, "Yoan");
	Horde->announce();
	delete[] Horde;
	return (0);
}
