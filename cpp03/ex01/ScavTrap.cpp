#include "ScavTrap.hpp"

// Orthodox Canonical form
ScavTrap::ScavTrap() : ClapTrap("default")
{
	// 상위 클래스의 멤버는 초기화 생성자에 못 쓴다.
	hitpoints = 100;
	EnergyPoints = 50;
	AttackDamage = 20;
	std::cout << "ScavTrap " << name << " constructor called." << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << name << " destructor called." << std::endl;
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
	std::cout << "ScavTrap " << name << " constructor called." << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name << " sets GateKeeper mode" << std::endl;
}