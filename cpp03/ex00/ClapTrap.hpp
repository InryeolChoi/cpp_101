#pragma once
#include <iostream>

class ClapTrap
{
	private:
		// member variable
		std::string 	name;
		unsigned int	hitpoints;
		unsigned int	energy;
		unsigned int	AttackDamage;

	public:
		// orthodox canonical form
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &other);
		ClapTrap &operator=(const ClapTrap &other);
		~ClapTrap();

		// member function
		unsigned int getDamage(void);
		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

