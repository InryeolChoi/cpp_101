#pragma once
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	protected:
		const unsigned int init_hp;
		const unsigned int init_ep;
		const unsigned int init_ad;

	public:
		// Orthodox Canonical form
		ScavTrap();
		ScavTrap(const ScavTrap &other);
		ScavTrap &operator=(const ScavTrap &other);
		~ScavTrap();

		// member function
		ScavTrap(std::string str);
		void guardGate();
	
		// overriding
		void attack(const std::string &target);
};