#pragma once
#include <iostream>

class ClapTrap
{
	protected:
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
		virtual ~ClapTrap();

		// member function
		ClapTrap(std::string str);
		unsigned int getDamage(void);
		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

