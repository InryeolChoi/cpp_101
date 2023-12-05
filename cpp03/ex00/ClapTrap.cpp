#include "ClapTrap.hpp"

class ClapTrap
{
	public:
		// orthodox canonical form
		ClapTrap();
		ClapTrap(const ClapTrap &clap);
		ClapTrap &operator=(const ClapTrap &clap);
		~ClapTrap();

		// member 

		// member function
		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};



if (ft_check_arg())
	return (1);
if ()