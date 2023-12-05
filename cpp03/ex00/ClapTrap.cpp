#include "ClapTrap.hpp"

// Orthodox Canonical Form
ClapTrap::ClapTrap() : name(), hitpoints(10), energy(10), AttackDamage(0) {}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	this->name = other.name;
	this->hitpoints = other.hitpoints;
	this->energy = other.energy;
	this->AttackDamage = other.AttackDamage;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->hitpoints = other.hitpoints;
		this->energy = other.energy;
		this->AttackDamage = other.AttackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap() {}

// ex00 : member function
ClapTrap::ClapTrap(std::string name) : name(name), hitpoints(10), energy(10), AttackDamage(0) {}

void	ClapTrap::attack(const std::string &target)
{
}

void	ClapTrap::takeDamage(unsigned int amount)
{
}

void	ClapTrap::beRepaired(unsigned int amount)
{
}