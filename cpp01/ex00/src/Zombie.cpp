#include "../includes/Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->_name = name;
}
Zombie::~Zombie()
{
	std::cout << this->_name << " has been killed" << std::endl;
}
void Zombie::announce()
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
