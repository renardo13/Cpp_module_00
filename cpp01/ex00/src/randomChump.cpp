#include "../includes/Zombie.hpp"

void randomChump( std::string name )
{
	Zombie new_Zombie(name);
	new_Zombie.announce();
}
