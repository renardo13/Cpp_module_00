#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"

int main()
{
	// ClapTrap lol("Julien");
	ScavTrap loli("Bernard");
	loli.attack("lol");

	loli.attack("Robert");
	std::cout << loli.getName() << " energy points left " << loli.getEnergyPoints() << " hits points left " << loli.getHitPoints() << " damage points left " << loli.getDamagePoints() << std::endl;
	loli.beRepaired(10);
	loli.takeDamage(10);
	loli.takeDamage(10);
	std::cout << loli.getName() << " energy points left " << loli.getEnergyPoints() << " hits points left " << loli.getHitPoints() << " damage points left " << loli.getDamagePoints() << std::endl;
	loli.beRepaired(10);
	loli.beRepaired(1);
	loli.attack("Yoan");
	loli.attack("Yyo");
}
