#include "../includes/Zombie.hpp"

Zombie::Zombie()
{

}
Zombie::~Zombie()
{
	
}

void Zombie::setName(std::string name)
{
	this->_name = name;
}

void Zombie::announce()
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
