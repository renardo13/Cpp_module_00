#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
		public :
			ScavTrap();
			~ScavTrap();
			ScavTrap(const std::string &name);
			ScavTrap(ScavTrap const &src);
			ScavTrap& operator=(ScavTrap const &src);

			void attack(std::string const &target);
			void guardGate();
};

#endif