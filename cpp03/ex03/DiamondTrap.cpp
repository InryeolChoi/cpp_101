#include "DiamondTrap.hpp"

// orthodox canonical form
DiamondTrap::DiamondTrap() : ClapTrap("default_clap_trap")
{
	this->name = "default";

	hitpoints = FragTrap::init_hp;
	EnergyPoints = ScavTrap::init_ep;
	AttackDamage = FragTrap::init_ad;

	std::cout << "DiamondTrap " << name << " constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(), ScavTrap(), FragTrap()
{
	*this = other; // =을 이미 오버로딩
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	ClapTrap::operator=(other);
	name = other.name;
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << name << " destructor called." << std::endl;
}

// member function
DiamondTrap::DiamondTrap(std::string str) : ClapTrap(str + "_clap_trap")
{
	this->name = str;

	hitpoints = FragTrap::init_hp;
	EnergyPoints = ScavTrap::init_ep;
	AttackDamage = FragTrap::init_ad;

	std::cout << "DiamondTrap " << name << " constructor called." << std::endl;
}

unsigned int DiamondTrap::gethitpoints() { return (hitpoints); }
unsigned int DiamondTrap::getAttackDamage() { return (AttackDamage); }
unsigned int DiamondTrap::getEnergyPoints() { return (EnergyPoints); }
std::string DiamondTrap::getname() {return (name); }

void	DiamondTrap::whoAmI()
{
	std::cout << "Diamond's name = " << name << ", ";
	std::cout << "ClapTrap's name = " << ClapTrap::name;
	std::cout << std::endl;
}

// overriding
void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}