#include "../includes/FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    std::cout << "FragTrap default constructor is called" << std::endl;
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor is called" << std::endl;
}

FragTrap::FragTrap(std::string const &name) : ClapTrap(name) 
{
    std::cout << "FragTrap constructor with parameters is called" << std::endl;
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
}

FragTrap::FragTrap(FragTrap const &cpy)
{
    std::cout << "FragTrap copy constructor is called" << std::endl;
    if(this != &cpy)
    {
        *this = cpy;
    }
}

FragTrap& FragTrap::operator=(FragTrap const &other) 
{
    std::cout << "FragTrap operator is called" << std::endl;
    this->_name = other._name;
    this->_hitPoints = other._hitPoints;
    this->_energyPoints = other._energyPoints;
    this->_attackDamage = other._attackDamage;
    return(*this);
}

void FragTrap::attack(const std::string &target)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		std::cout << "FragTrap " << this->_name << " attack " << target << " causing " << this->_attackDamage << " points of damage" << std::endl;
		this->_energyPoints--;
	}
	else if (this->_hitPoints <= 0)
	{
		std::cout << "FragTrap " << this->_name << " cannot attack because it has no hit points left!" << std::endl;
	}
	else
	{
		std::cout << "FragTrap " << this->_name << "has no energy left and cannot attacks " << target << std::endl;
	}
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap asks for an high fives" << std::endl;
}
