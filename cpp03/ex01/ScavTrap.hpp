#pragma once
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		// Orthodox Canonical form
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &s);
		ScavTrap &operator=(const ScavTrap &s);
		~ScavTrap();

		// member function
		void guardGate();
		void attack(std::string const &target);
};