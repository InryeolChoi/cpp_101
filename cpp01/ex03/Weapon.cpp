#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type(type)
{}

Weapon::~Weapon() {}

std::string const &Weapon::getType() const
{
	return (type);
}

void	Weapon::setType(const std::string str)
{
	type = str;
}