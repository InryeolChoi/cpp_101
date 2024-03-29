#include "Character.hpp"

// orthodox canonical form
Character::Character() : name("default")
{
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
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
			{
				delete inventory[i];
				inventory[i] = NULL;
				inventory[i] = other.inventory[i]->clone();
			}
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
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
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
			std::cout << "fully equipped!" << std::endl;
			inventory[i] = materia;
			return ;
		}
	}
	std::cout << "inventory index is full" << std::endl;
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4)
	{
		if (inventory[idx])
		{
			// NULL로 덮어씌우기 전 주소값 이전
			floor.additem(idx, inventory[idx]);
			inventory[idx] = NULL;
			std::cout << "unequip finished" << std::endl;
		}
		else
			std::cout << "error : already NULL" << std::endl;
	}
	else
		std::cout << "error : invalid index" << std::endl;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < 4)
	{
		if (inventory[idx])
			inventory[idx]->use(target);
		else
			std::cout << "error : inventory is empty" << std::endl;
	}
	else
		std::cout << "error : invalid index" << std::endl;
}
