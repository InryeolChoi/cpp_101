#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap a("a"); // 10, 10, 0
	ScavTrap b("b"); // 100, 50, 20
	std::cout << std::endl;

	// b -> a 공격 (ScavTrap의 공격 : 20)
	b.attack("a");
	a.takeDamage(b.getDamage());
	std::cout << std::endl;

	// a 회복
	a.beRepaired(20);
	std::cout << std::endl;

	// b의 guardGate 모드 키기
	b.guardGate();
	std::cout << std::endl;

	// a -> b 공격 (ClapTrap의 공격 : 0)
	a.attack("b");
	b.takeDamage(a.getDamage());
	std::cout << std::endl;

	return 0;
}