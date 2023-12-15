#include "Floor.hpp"

// orthodox canonical form
Floor::Floor()
{
	for (int i = 0; i < 4; i++)
		slot[i] = NULL;
}

Floor::Floor(const Floor &other)
{
	*this = other;
}

Floor &Floor::operator=(const Floor &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
			slot[i] = other.slot[i];
	}
	return (*this);
}

Floor::~Floor()
{
	for (int i = 0; i < 4; i++)
	{
		if (slot[i] != NULL)
			delete slot[i];
	}
}

void Floor::additem(int idx, AMateria *item)
{
	if (idx >= 0 && idx < 4 && slot[idx] != NULL)
	{
		for (int i = 0; i < 4; i++)
			slot[idx] = item;
	}
	else
		std::cout << "wrong index" << std::endl;
}