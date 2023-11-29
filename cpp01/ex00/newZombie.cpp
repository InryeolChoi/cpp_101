#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
	Zombie *newzombie2 = new Zombie(name);
	return (newzombie2);
}