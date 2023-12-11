#include "ScavTrap.hpp"

// Orthodox Canonical form
ScavTrap::ScavTrap() : ClapTrap("default"), init_hp(100), init_ep(50), init_ad(20)
{
	hitpoints = init_hp;
	EnergyPoints = init_ep;
	AttackDamage = init_ad;
	std::cout << "ScavTrap " << name << " constructor called." << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << name << " destructor called." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(), init_hp(other.init_hp), init_ep(other.init_ep), init_ad(other.init_hp)
{
	name = other.name;
	AttackDamage = other.AttackDamage;
	EnergyPoints = other.EnergyPoints;
	hitpoints = other.hitpoints;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
	{
		name = other.name;
		AttackDamage = other.AttackDamage;
		EnergyPoints = other.EnergyPoints;
		hitpoints = other.hitpoints;
	}
	return (*this);
}

// member function
ScavTrap::ScavTrap(std::string name) : ClapTrap(name), init_hp(100), init_ep(50), init_ad(20)
{
	hitpoints = init_hp;
	EnergyPoints = init_ep;
	AttackDamage = init_ad;
	std::cout << "ScavTrap " << name << " constructor called." << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name << " sets GateKeeper mode" << std::endl;
}

// overriding
void	ScavTrap::attack(const std::string &target)
{
	if (!hitpoints || !EnergyPoints)
		std::cout << "ScavTrap " << name << " can't do anything" << std::endl;
	else
	{
		EnergyPoints--; // 에너지 소모
		std::cout << "ScavTrap " << name << " attacks " << target;
		std::cout << ", causing " << AttackDamage << " points of damage ";
		std::cout << "and 1 EnergyPoint decrease.";
		std::cout << std::endl;
	}
}
