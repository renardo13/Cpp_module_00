#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <iostream>
#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"
#include "../includes/FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
    private :
        std::string _name;

    public :
        DiamondTrap();
		~DiamondTrap();
		DiamondTrap(std::string const &name);
		DiamondTrap(DiamondTrap const &src);
		DiamondTrap& operator=(DiamondTrap const &src);

		void attack(const std::string& target);
        void whoAmI();

};

#endif