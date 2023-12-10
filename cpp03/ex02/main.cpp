#include "FragTrap.hpp"

int main()
{
	ClapTrap A("a");
	FragTrap B("b");
	std::cout << std::endl;

	// A -> B 공격 (ClapTrap의 공격 : 0)
	A.attack("a");
	B.takeDamage(A.getDamage());
	std::cout << std::endl;

	// B 회복
	B.beRepaired(0);
	std::cout << std::endl;

	// B -> A 공격 (FragTrap의 공격 : 30)
	B.attack("b");
	A.takeDamage(B.getDamage());
	std::cout << std::endl;

	// A 회복 (불가능)
	A.beRepaired(42);
	std::cout << std::endl;

	// B의 highFivesGuys()
	B.highFivesGuys();
	std::cout << std::endl;

	return 0;
}