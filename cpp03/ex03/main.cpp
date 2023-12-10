#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap d1("John");
	ClapTrap	c1("Hammond");

	d1.whoAmI();

	return 1;
}