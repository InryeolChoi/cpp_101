#include "FragTrap.hpp"

// Orthodox Canonical form
FragTrap::FragTrap() : ClapTrap("default")
{
	// 상위 클래스의 멤버는 초기화 생성자에 못 쓴다.
	hitpoints = 100;
	EnergyPoints = 100;
	AttackDamage = 30;

	std::cout << "FragTrap " << name << " constructor called." << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << name << " destructor called." << std::endl;
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
FragTrap::FragTrap(std::string str) : ClapTrap(str)
{
	// 상위 클래스의 멤버는 초기화 생성자에 못 쓴다.
	hitpoints = 100;
	EnergyPoints = 100;
	AttackDamage = 30;
	std::cout << "FragTrap " << name << " constructor called." << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << name << " want to do highFive!" << std::endl;
}
