#include "Zombie.hpp"

int main()
{
	int	n;
	Zombie *horde;

	std::cout << "how many zombies do you want? (Do not type more than 100000)";
	std::cin >> n;
	horde = zombieHorde(n, "zombie");
	for (int i = 0; i < n; i++)
		horde[i].announce();
	delete[] horde;

	return (0);
}