#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
		public :
			ScavTrap();
			~ScavTrap();
			ScavTrap(const std::string &name);
			ScavTrap(ScavTrap const &src);
			ScavTrap& operator=(ScavTrap const &src);

			virtual void attack(std::string const &target) = 0;
			void guardGate();
};

#endif