#include "DiamondTrap.hpp"

// Orthodox Canonical form
DiamondTrap::DiamondTrap()
{
	ClapTrap::name = "default";
	std::cout << "DiamondTrap " << name << " is created." << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << name << "is now died." << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &other)
	: ClapTrap(other), ScavTrap(other), FragTrap(other)
{
	std::cout << "DiamondTrap " << name << "is copied from other." << std::endl;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		name = other.name;
	}
	return (*this);
}

// member function
DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name")
{
	this->name = name;
	this->hitpoints = FragTrap::hitpoints;
	this->EnergyPoints = ScavTrap::EnergyPoints;
	this->AttackDamage = FragTrap::AttackDamage;

	std::cout << "DiamondTrap " << name << " is created." << std::endl;
}

void	DiamondTrap::whoAmI()
{
	if (this->hitpoints <= 0)
		std::cout << "DiamondTrap cannot do anything" << std::endl;
	else
	{
		std::cout << "DiamondTrap's name = " << name << std::endl;
		std::cout << "DiamondTrap's ClapTrap name = " << ClapTrap::name << std::endl;
	}
}