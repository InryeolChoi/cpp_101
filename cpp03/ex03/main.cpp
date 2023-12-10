#include "DiamondTrap.hpp"

int main(void)
{
	ClapTrap A("a");
	ScavTrap A2("a2");
	DiamondTrap B("b");
	std::cout << std::endl;

	// 제대로 상속이 되었는지 체크...
	std::cout << "<inheritance check...>" << std::endl;
	std::cout << B.getname() << "'s hitpoints = " << B.gethitpoints() << std::endl;
	std::cout << B.getname() << "'s EnergyPoints = " << B.getEnergyPoints() << std::endl;
	std::cout << B.getname() << "'s AttackDamage = " << B.getAttackDamage() << std::endl;
	std::cout << std::endl;

	// whoamI()
	B.whoAmI();
	std::cout << std::endl;

	// highFive()
	B.highFivesGuys();
	std::cout << std::endl;

	// guardGate()
	B.guardGate();
	std::cout << std::endl;

	// A2 -> B 공격
	A2.attack("B");
	B.takeDamage(A2.getDamage());
	std::cout << std::endl;

	// B -> A 공격
	B.attack("A2");
	A2.takeDamage(B.getDamage());
	std::cout << std::endl;
	return 0;
}