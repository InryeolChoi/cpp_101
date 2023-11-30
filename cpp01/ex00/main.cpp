#include "Zombie.hpp"

int main()
{
	// 스택(정적 할당)으로 만든 좀비
	std::cout << "<< zombies made by stack >>" << std::endl;
	Zombie zombie1("zombie1");
	Zombie zombie2("zombie2");
	Zombie zombie3;

	zombie1.announce();
	zombie2.announce();
	zombie3.announce();
	randomChump("randomChump");
	std::cout << std::endl;

	// 힙(동적 할당)으로 만든 좀비
	std::cout << "<< zombies made by heap >>" << std::endl;
	Zombie *zombieX;

	zombieX = newZombie("zombieX");
	zombieX->announce();
	delete(zombieX);

	return (0);
}