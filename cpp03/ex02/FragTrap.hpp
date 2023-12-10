#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		// Orthodox Canonical form
		FragTrap();
		FragTrap(const FragTrap &other);
		FragTrap &operator=(const FragTrap &other);
		~FragTrap();

		// member function
		FragTrap(std::string name);
		void highFivesGuys(void);
};