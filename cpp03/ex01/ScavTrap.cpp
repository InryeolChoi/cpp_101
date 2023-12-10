#include "ScavTrap.hpp"

// Orthodox Canonical form
ScavTrap::ScavTrap() : ClapTrap("default")
{
	// 상위 클래스의 멤버는 초기화 생성자에 못 쓴다.
	hitpoints = 100;
	EnergyPoints = 50;
	AttackDamage = 20;
	std::cout << "ScavTrap " << name << " is created." << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << name << " is now dead." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap()
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
ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	// 상위 클래스의 멤버는 초기화 생성자에 못 쓴다.
	hitpoints = 100;
	EnergyPoints = 50;
	AttackDamage = 20;
	std::cout << "ScavTrap " << name << " is created." << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name << " has entered the Gate Keeper mode" << std::endl;
	EnergyPoints = 10;

	std::cout << "ScavTrap " << name << " has fully recovered his energy" << std::endl;
}

// overriding
void	ScavTrap::attack(const std::string &target)
{
	if (!hitpoints || !EnergyPoints)
		std::cout << "ScavTrap " << name << " can't do anything" << std::endl;
	else
	{
		std::cout << "ScavTrap " << name << " attacks " << target;
		std::cout << ", Causing " << AttackDamage << " points of damage";
		std::cout << std::endl;
		EnergyPoints--; // 에너지 소모
	}
}
