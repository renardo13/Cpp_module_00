#include "../includes/DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	std::cout << "DiamondTrap default constructor is called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string const &name) : ClapTrap(name + "_clap_name")
{
	std::cout << "DiamondTrap constructor with parameters is called" << std::endl;
    this->_name = name;
    this->_attackDamage = FragTrap::_attackDamage;
    this->_hitPoints = FragTrap::_hitPoints;
    this->_energyPoints = ScavTrap::_energyPoints;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor is called" << std::endl;
}
DiamondTrap::DiamondTrap(DiamondTrap const &other)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	operator=(other);
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &other)
{
    this->_name = other._name;
    this->_attackDamage = FragTrap::_attackDamage;
    this->_hitPoints = FragTrap::_hitPoints;
    this->_energyPoints = ScavTrap::_energyPoints;
	return(*this);
}

void DiamondTrap::attack(std::string const &target)
{
    std::cout << "DiamondTrap attack via ScavTrap attack function" << std::endl;
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void)
{
    std::cout << "My name is : " << this->_name << std::endl;
    std::cout << "The name of ClapTrap is : " << ClapTrap::_name << std::endl;
}
