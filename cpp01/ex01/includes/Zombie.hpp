#ifndef ZOMBIE_HPP

# define ZOOMBIE_HPP

# include <iomanip>
# include <iostream>
# include <limits>

class Zombie
{
  private:
	std::string _name;

  public:
	Zombie(void);
	~Zombie(void);
	void announce(void);
	void setName(std::string name);
};

Zombie	*zombieHorde(int N, std::string name);

#endif