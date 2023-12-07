#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap A;
	ScavTrap B;

	A.attack();
	B.takeDamage();
	B.beRepaired();

	B.attack();
	A.takeDamage();
	A.beRepaired();

	A.guardGate();
}