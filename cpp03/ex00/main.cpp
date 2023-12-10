#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap a("a");
	ClapTrap b("b");
	std::cout << std::endl;

	// a -> b
	a.attack("b");
	b.takeDamage(a.getDamage());
	std::cout << std::endl;

	// b repairs itself
	b.beRepaired(3);
	std::cout << std::endl;

	// b -> a
	b.attack("a");
	a.takeDamage(a.getDamage());
	std::cout << std::endl;

	// a repairs itself
	a.beRepaired(2);
	std::cout << std::endl;

	return 0;
}