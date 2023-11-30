#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
}

HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon &Weapon)
{
	this->weapon = &Weapon;
}

void HumanB::attack(void)
{
	std::cout << name << " attacks with their ";
	std::cout << this->weapon->getType() << std::endl;
}
