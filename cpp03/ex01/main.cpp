#include "ScavTrap.hpp"

int main(void)
{
	std::string s1 = "Peter";
	std::string s2 = "John";
	ClapTrap claptrap(s1);
	ScavTrap scavtrap(s2);
	std::cout << std::endl;

	claptrap.attack(s2);
	scavtrap.takeDamage(0);
	scavtrap.beRepaired(18);
	std::cout << std::endl;

	scavtrap.attack(s1);
	claptrap.takeDamage(20);
	scavtrap.attack(s1);
	claptrap.beRepaired(42);
	std::cout << std::endl;

	scavtrap.guardGate();
	std::cout << std::endl;

	return (0);
}