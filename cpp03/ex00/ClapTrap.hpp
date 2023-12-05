#pragma once
#include <iostream>

class ClapTrap
{
	private:
		// member variable
		std::string name;
		int	hitpoints;
		int	energy;
		int	AttackDamage;

	public:
		// orthodox canonical form
		ClapTrap();
		ClapTrap(const ClapTrap &other);
		ClapTrap &operator=(const ClapTrap &other);
		~ClapTrap();

		// member function
		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

