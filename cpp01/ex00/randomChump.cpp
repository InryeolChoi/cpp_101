#include "Zombie.hpp"

void	randomChump(std::string name)
{
	// 힙
	// Zombie *zombie = new Zombie(name);
	// zombie->announce();
	// delete zombie;

	// 스택
	Zombie	zombie(name);
	zombie.announce();
}