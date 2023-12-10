#pragma once
#include <iostream>

class ClapTrap
{
	private:
		// member variable
		std::string 	name;
		unsigned int	hitpoints;
		unsigned int	EnergyPoints;
		unsigned int	AttackDamage;

	public:
		// orthodox canonical form
		ClapTrap();
		ClapTrap(const ClapTrap &other);
		ClapTrap &operator=(const ClapTrap &other);
		~ClapTrap();

		// member function
		ClapTrap(std::string name);
		unsigned int getDamage(void);
		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

