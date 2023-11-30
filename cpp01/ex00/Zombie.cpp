#include "Zombie.hpp"

Zombie::Zombie() : name("Zombie_origin") {
	return ;
}

Zombie::Zombie(std::string name) : name(name) {
	return ;
}

Zombie::~Zombie()
{
	std::cout << this->name << " is dead.." << std::endl;
}

void	Zombie::announce()
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}