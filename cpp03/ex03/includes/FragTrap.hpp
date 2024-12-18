#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
		public :
			FragTrap();
			~FragTrap();
			FragTrap(const std::string &name);
			FragTrap(FragTrap const &src);
			FragTrap& operator=(FragTrap const &src);

            void attack(const std::string &target);
			void highFivesGuys(void);
};

#endif