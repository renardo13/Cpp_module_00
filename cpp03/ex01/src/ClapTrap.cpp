#include "../includes/ClapTrap.hpp"

//Canonic functions

ClapTrap::ClapTrap() : _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap default constructor is called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10),
	_energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap constructor is called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor is called" << std::endl;
}
ClapTrap::ClapTrap(ClapTrap const &other)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	operator=(other);
}

ClapTrap &ClapTrap::operator=(ClapTrap const &other)
{
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	return(*this);
}

void ClapTrap::attack(const std::string &target)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		std::cout << "ClapTrap " << this->_name << " attack " << target << " causing " << this->_attackDamage << " points of damage" << std::endl;
		this->_energyPoints--;
	}
	else if (this->_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " cannot attack because it has no hit points left!" << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << this->_name << "has no energy left and cannot attacks " << target << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints <= 0)
		std::cout << this->_name << " cannot be attacked because he has no energy points left" << std::endl;
	else
	{
		std::cout << this->_name << " is attack and loose " << amount << " points of damage" << std::endl;
		this->_hitPoints -= amount;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		this->_hitPoints += amount;
		this->_energyPoints--;
	}
	else
		std::cout << this->_name << " cannot be repaired because he has no energy points left" << std::endl;
}

std::string ClapTrap::getName() const
{
	return (this->_name);
}

// Getter pour _energyPoints
int	ClapTrap::getEnergyPoints(void) const
{
	return (this->_energyPoints);
}

// Getter pour _hitPoints
int ClapTrap::getHitPoints() const
{
	return (this->_hitPoints);
}


int ClapTrap::getDamagePoints() const
{
	return (this->_attackDamage);
}