#include "Character.hpp"

// orthodox canonical form
Character::Character() : name("default")
{
	std::cout << "Character constructor called" << std::endl;
}

Character::Character(const Character &other) 
{
	name = other.getName();
	for (int i = 0; i < 4; i++)
	{
		if (other.inventory[i])
			inventory[i] = other.inventory[i]->clone();
		else
			inventory[i] = NULL;
	}
}

Character &Character::operator=(const Character &other) 
{
	if (this != &other)
	{
		this->name = other.getName();
		for (int i = 0; i < 4; i++)
		{
			if (other.inventory[i])
				this->inventory[i] = other.inventory[i]->clone();
			else
				this->inventory[i] = NULL;
		}
	}
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i])
			delete inventory[i];
	}
}

// member function
Character::Character(std::string str) : name(str)
{
	std::cout << "Character constructor called" << std::endl;
}

std::string const &Character::getName() const
{
	return (name);
}

void Character::equip(AMateria *materia)
{
	for (int i = 0; i < 4; i++)
	{
		if (!inventory[i])
		{
			inventory[i] = materia;
			return ;
		}
	}
	std::cout << "inventory index is full" << std::endl;
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4)
		inventory[idx] = NULL;
	else
		std::cout << "error : invalid index" << std::endl;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < 4)
		inventory[idx]->use(target);
	else
		std::cout << "error : invalid index" << std::endl;
}
