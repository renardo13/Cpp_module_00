#ifndef ZOMBIE_HPP

#define ZOOMBIE_HPP

#include <iostream>
#include <iomanip>
#include <limits>

class Zombie
{
	private:
		std::string _name;
	public:
		Zombie(std::string name);
		~Zombie();
		void announce( void );
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif