#ifndef WEAPON_HPP

# define WEAPON_HPP

# include <iostream>
# include <limits>
# include <string>

class Weapon
{
  private:
	std::string _type;

  public:
	Weapon(std::string type);
	~Weapon();
	const std::string& getType(void);
	void setType(std::string type);
};

#endif