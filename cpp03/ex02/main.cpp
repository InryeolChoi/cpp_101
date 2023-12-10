#include "FragTrap.hpp"

int main()
{
	ClapTrap claptrap("Peter");
	FragTrap fragtrap("John");

	std::cout << std::endl;
	claptrap.attack("Peter");
	fragtrap.takeDamage(0);
	fragtrap.beRepaired(18);

	std::cout << std::endl;
	fragtrap.attack("John");
	claptrap.takeDamage(20);
	claptrap.beRepaired(42);

	std::cout << std::endl;
	fragtrap.highFivesGuys();
}