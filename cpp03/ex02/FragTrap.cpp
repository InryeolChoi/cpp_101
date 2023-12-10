#include "FragTrap.hpp"

// Orthodox Canonical form
FragTrap::FragTrap() : ClapTrap("default")
{
	hitpoints = 100;
	EnergyPoints = 100;
	AttackDamage = 30;
	std::cout << "FragTrap " << name << " is created." << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << name << " is now dead." << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap()
{
	*this = other; // =을 이미 오버로딩
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)
	{
		this->hitpoints = other.hitpoints;
		this->EnergyPoints = other.EnergyPoints;
		this->AttackDamage = other.AttackDamage;
	}
	return (*this);
}

// member function
FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	hitpoints = 100;
	EnergyPoints = 100;
	AttackDamage = 30;
	std::cout << "FragTrap " << name << " is created." << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << name << " want to do highFive!" << std::endl;
}
