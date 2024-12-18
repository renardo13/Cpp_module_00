#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"
#include "../includes/FragTrap.hpp"

int main()
{
	ScavTrap scav("scav");
	FragTrap frag("frag");

	scav.attack("frag");
	frag.attack("scav");

	std::cout << scav.getName() << " energy points left " << scav.getEnergyPoints() << " hits points left " << scav.getHitPoints() << " damage points left " << scav.getDamagePoints() << std::endl;
	scav.beRepaired(10);

	scav.takeDamage(10);
	scav.takeDamage(10);
	frag.takeDamage(10);
	frag.highFivesGuys();

	std::cout << frag.getName() << " energy points left " << frag.getEnergyPoints() << " hits points left " << frag.getHitPoints() << " damage points left " << frag.getDamagePoints() << std::endl;
	scav.beRepaired(10);
	scav.beRepaired(1);
}


