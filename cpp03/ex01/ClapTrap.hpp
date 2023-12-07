#pragma once
#include <iostream>

class ClapTrap
{
	protected:
		// member variable
		std::string 	name;
		unsigned int	hitpoints;
		unsigned int	energy;
		unsigned int	AttackDamage;

	public:
		// orthodox canonical form
		ClapTrap();
		ClapTrap(const ClapTrap &other);
		ClapTrap &operator=(const ClapTrap &other);
		virtual ~ClapTrap();	// virtual로 변경

		// ex00 : member function
		ClapTrap(std::string name);
		unsigned int getDamage(void);
		virtual void attack(const std::string &target); // virtual로 변경
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		// ex01 : member function
};

