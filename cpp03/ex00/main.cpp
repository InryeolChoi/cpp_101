#include "ClapTrap.hpp"

int main(int ac, char **av)
{
	ClapTrap a;
	ClapTrap b;

	a.attack(b);
	b.attack(a);
	a.beRepaired();
	b.attack();

}