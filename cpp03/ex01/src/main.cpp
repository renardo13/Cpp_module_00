#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"

int main()
{
	// ClapTrap lol("Julien");
	ScavTrap scav("Bernard");
	scav.attack("lol");

	scav.attack("Robert");
	std::cout << scav.getName() << " energy points left " << scav.getEnergyPoints() << " hits points left " << scav.getHitPoints() << " damage points left " << scav.getDamagePoints() << std::endl;
	scav.beRepaired(10);
	scav.takeDamage(10);
	scav.takeDamage(10);
	std::cout << scav.getName() << " energy points left " << scav.getEnergyPoints() << " hits points left " << scav.getHitPoints() << " damage points left " << scav.getDamagePoints() << std::endl;
	scav.beRepaired(10);
	scav.beRepaired(1);
	scav.attack("Yoan");
	scav.attack("Yyo");
}
