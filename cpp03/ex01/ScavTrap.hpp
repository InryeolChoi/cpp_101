#pragma once
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		// Orthodox Canonical form
		ScavTrap();
		ScavTrap(const ScavTrap &other);
		ScavTrap &operator=(const ScavTrap &other);
		~ScavTrap();

		// member function
		ScavTrap(std::string name);
		void guardGate();
};