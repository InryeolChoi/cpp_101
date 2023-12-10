#pragma once
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

// ScavTrap : virtual 키워드 이용, 가상상속
// FragTrap : virtual 키워드 이용, 가상상속
class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string	name;

	public:
		// orthodox canonical form
		DiamondTrap();
		DiamondTrap(const DiamondTrap &other);
		DiamondTrap &operator=(const DiamondTrap &other);
		~DiamondTrap();

		// member function
		DiamondTrap(std::string str);
		unsigned int gethitpoints();
		unsigned int getAttackDamage();
		unsigned int getEnergyPoints();
		std::string getname();
		void whoAmI();

		// overriding
		void attack(const std::string &target);
};