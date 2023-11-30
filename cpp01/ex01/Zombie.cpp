#include "Zombie.hpp"

Zombie::Zombie() : name("Zombie_A") {
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

void	Zombie::setName(std::string name){
	this->name = name;
}