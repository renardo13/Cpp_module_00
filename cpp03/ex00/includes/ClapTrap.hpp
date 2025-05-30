#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	private:
		std::string _name;
		int _hitPoints; // health points
		int _energyPoints; // energy
		int _attackDamage; // Damage points when attacking

	public:
		ClapTrap(void);
		ClapTrap(std::string const &name);
		~ClapTrap(void);
		ClapTrap(ClapTrap const &src);
		ClapTrap &operator=(ClapTrap const &other);

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		//Getter Setter
		int getHitPoints() const;
		int	getEnergyPoints(void) const;
		int	getDamagePoints(void) const;
		std::string getName() const;
};

#endif