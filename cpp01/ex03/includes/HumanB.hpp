#ifndef HUMANB_HPP

# define HUMANB_HPP

# include <iomanip>
# include <iostream>
# include <limits>
# include <string>
# include "Weapon.hpp"

class HumanB
{
  private:
	std::string _name;
	Weapon 		*_weapon;

  public:
	HumanB(std::string name);
	~HumanB(void);
	void attack() const;
	void setWeapon(Weapon &Weapon);
};

#endif