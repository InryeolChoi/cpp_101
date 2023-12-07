#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap a("a");
	ClapTrap b("b");

	// a -> b
	a.attack("b");
	b.takeDamage(a.getDamage());

	// b repairs itself
	b.beRepaired(3);

	// b -> a
	b.attack("a");
	a.takeDamage(a.getDamage());

	// a repairs itself
	a.beRepaired(2);

	return 0;
}