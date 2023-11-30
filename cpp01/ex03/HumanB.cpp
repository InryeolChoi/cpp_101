#include "HumanB.hpp"

HumanB::HumanB(std::string name): weapon(NULL)
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
	if (this->weapon != NULL)
	{
		std::cout << this->weapon->getType() << std::endl;
	}
}
