#include "FragTrap.hpp"

// Orthodox Canonical form
FragTrap::FragTrap() : ClapTrap("default"), init_hp(100), init_ep(100), init_ad(30)
{
	hitpoints = init_hp;
	EnergyPoints = init_ep;
	AttackDamage = init_ad;
	std::cout << "FragTrap " << name << " constructor called." << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << name << " destructor called." << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(), init_hp(other.init_hp), init_ep(other.init_ep), init_ad(other.init_ad)
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
FragTrap::FragTrap(std::string name) : ClapTrap(name), init_hp(100), init_ep(100), init_ad(30)
{
	hitpoints = init_hp;
	EnergyPoints = init_ep;
	AttackDamage = init_ad;
	std::cout << "FragTrap " << name << " constructor called." << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << name << " want to do highFive!" << std::endl;
}
