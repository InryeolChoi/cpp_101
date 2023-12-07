#include "ScavTrap.hpp"

// Orthodox Canonical form
ScavTrap::ScavTrap(std::string name) : ClapTrap(name) 
{
	std::cout << "ScavTrap " << name << " is created." << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << name << " is now dead." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &s)
{
	name = s.name;
	AttackDamage = s.AttackDamage;
	energy = s.energy;
	hitpoints = s.hitpoints;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &s)
{
	if (this != &s)
	{
		name = s.name;
		AttackDamage = s.AttackDamage;
		energy = s.energy;
		hitpoints = s.hitpoints;
	}
	return (*this);
}

// member function
void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name << " has entered the Gate Keeper mode" << std::endl;
	energy = 10;
	std::cout << "ScavTrap " << name << " has fully recovered his energy" << std::endl;
}
