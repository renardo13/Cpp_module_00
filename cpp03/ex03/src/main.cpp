#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"
#include "../includes/FragTrap.hpp"
#include "../includes/DiamondTrap.hpp"

int main()
{
	DiamondTrap diam("diam");

	diam.beRepaired(25);

	std::cout << std::string(50, '*') << std::endl;
	diam.attack("Roger");
	diam.beRepaired(25);
	std::cout << std::string(50, '*') << std::endl;
	diam.whoAmI();
	std::cout << std::string(50, '*') << std::endl;
	return(0);
}


