#include "../includes/ScavTrap.hpp"
#include "../includes/ClapTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap default constructeur is called" << std::endl;
	this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
}
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructeur is called" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
	std::cout << "ScavTrap constructor with prameters is called" << std::endl;
	this->_name = name;
	this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
}

ScavTrap::ScavTrap(ScavTrap const &other)
{
	operator=(other);
}

ScavTrap &ScavTrap::operator=(ScavTrap const &src)
{
	this->_name = src._name;
	this->_energyPoints = src._energyPoints;
	this->_hitPoints = src._hitPoints;
	this->_attackDamage = src._attackDamage;
	return(*this);
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}

void ScavTrap::attack(std::string const &target)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		std::cout << "ScavTrap " << this->_name << " attack " << target << " causing " << this->_attackDamage << " points of damage" << std::endl;
		this->_energyPoints--;
	}
	else if (this->_hitPoints <= 0)
	{
		std::cout << "ScavTrap " << this->_name << " cannot attack because it has no hit points left!" << std::endl;
	}
	else
	{
		std::cout << "ScavTrap " << this->_name << "has no energy left and cannot attacks " << target << std::endl;
	}
}
