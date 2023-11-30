#include "Zombie.hpp"

Zombie	*zombieHorde(int n, std::string name)
{
	Zombie *horde = new Zombie[n];
	std::stringstream ss;

	for (int i = 0; i < n; i++)
	{
		ss << i;
		horde[i].setName(name + ss.str());
		ss.str("");
	}
	return (horde);
}