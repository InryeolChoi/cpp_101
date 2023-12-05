#include "ClapTrap.hpp"

// Orthodox Canonical Form
ClapTrap::ClapTrap() : name(), hitpoints(10), energy(10), damage(0) {}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	this->name = other.name;
	this->hitpoints = other.hitpoints;
	this->energy = other.energy;
	this->damage = other.damage;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->hitpoints = other.hitpoints;
		this->energy = other.energy;
		this->damage = other.damage;
	}
	return (*this);
}

ClapTrap::~ClapTrap() {}

// ex00 : member function
void	ClapTrap::attack(const std::string &target)
{
	if (hitpoints > 0 || energy > 0)
	{
		std::cout << "ClapTrap " << name << " attacks " << target 
		<< ", causing " << damage << " points of damage!";
		energy--;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{

}

void	ClapTrap::beRepaired(unsigned int amount)
{
	energy++;
}