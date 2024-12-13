#include "../includes/ClapTrap.hpp"

int main()
{
	ClapTrap lol("Julien");
	lol.attack("Robert");
	std::cout << lol.getName() << " energy points left " << lol.getEnergyPoints() << " hits points left " << lol.getHitPoints() << " damage points left " << lol.getDamagePoints() << std::endl;
	lol.beRepaired(10);
	lol.takeDamage(10);
	lol.takeDamage(10);
	std::cout << lol.getName() << " energy points left " << lol.getEnergyPoints() << " hits points left " << lol.getHitPoints() << " damage points left " << lol.getDamagePoints() << std::endl;
	lol.beRepaired(10);
	lol.beRepaired(1);
	lol.attack("Yoan");
	lol.attack("Yyo");
}
