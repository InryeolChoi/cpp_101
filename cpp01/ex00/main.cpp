#include "Zombie.hpp"

int main()
{
	Zombie newzombie();
	Zombie *newzombie2 = newZombie("");

	randomChump("");
	newzombie2->announce();

	delete newzombie2;
	return (0);
}