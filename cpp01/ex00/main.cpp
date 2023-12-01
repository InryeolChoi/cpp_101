#include "Zombie.hpp"

int main()
{
	// 힙(동적 할당)으로 만든 좀비
	std::cout << "<< zombies made by heap >>" << std::endl;
	Zombie *zombieX;

	zombieX = newZombie("zombieX");
	zombieX->announce();
	delete zombieX;
	std::cout << std::endl;

	// random으로 만든 좀비
	std::cout << "<< zombies made by random >>" << std::endl;
	randomChump("randomChump");
	std::cout << std::endl;

	// 스택(정적 할당)으로 만든 좀비
	std::cout << "<< zombies made by stack >>" << std::endl;
	Zombie zombie;
	Zombie zombie1("zombie1");
	Zombie zombie2("zombie2");

	zombie.announce();
	zombie1.announce();
	zombie2.announce();
	return (0);
}