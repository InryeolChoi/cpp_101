#include "ClapTrap.hpp"

// Orthodox Canonical Form
ClapTrap::ClapTrap() : name("default"), hitpoints(10), EnergyPoints(10), AttackDamage(0) 
{
	std::cout << "ClapTrap " << name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;

	this->name = other.name;
	this->hitpoints = other.hitpoints;
	this->EnergyPoints = other.EnergyPoints;
	this->AttackDamage = other.AttackDamage;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "ClapTrap " << name << " operator= called" << std::endl;
	if (this != &other)
	{
		this->name = other.name;
		this->hitpoints = other.hitpoints;
		this->EnergyPoints = other.EnergyPoints;
		this->AttackDamage = other.AttackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << name << " destructor called" << std::endl;
}

// member function
ClapTrap::ClapTrap(std::string str) : name(str), hitpoints(10), EnergyPoints(10), AttackDamage(0) 
{
	std::cout << "ClapTrap " << name << " constructor called" << std::endl;
}

void	ClapTrap::attack(const std::string &target)
{
	if (!hitpoints || !EnergyPoints)
		std::cout << "ClapTrap " << name << " can't do anything" << std::endl;
	else
	{
		std::cout << "ClapTrap " << name << " attacks " << target;
		std::cout << ", Causing " << AttackDamage << " points of damage";
		std::cout << std::endl;
		EnergyPoints--; // 에너지 소모
	}
}

unsigned int	ClapTrap::getDamage(void)
{
	return (AttackDamage);
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > EnergyPoints)
	{
		EnergyPoints = 0;
		std::cout << "ClapTrap " << name << " is attacked, ";
		std::cout << "and is not quite well..";
	}
	else if (amount == 0)
	{
		std::cout << "ClapTrap " << name << " is not attacked, ";
		std::cout << "and has " << EnergyPoints << " left.";		
	}
	else
	{
		EnergyPoints -= amount;
		std::cout << "ClapTrap " << name << " is attacked, ";
		std::cout << "and has " << EnergyPoints << " left.";
	}
	std::cout << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!hitpoints || !EnergyPoints)
		std::cout << "ClapTrap " << name << " can't do anything" << std::endl;
	else
	{
		hitpoints += amount;	// hitpoints 충전
		if (hitpoints > 10)
			hitpoints = 10;
		EnergyPoints--;			// 에너지 소모

		std::cout << "ClapTrap " << name << " gets " << amount << " hitpoints. ";
		std::cout << "It has now " << hitpoints << " hitpoints." << std::endl;
	}
}
