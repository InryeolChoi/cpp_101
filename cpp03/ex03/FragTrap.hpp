#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
		// Orthodox Canonical form
		FragTrap();
		FragTrap(const FragTrap &other);
		FragTrap &operator=(const FragTrap &other);
		~FragTrap();

		// member function
		FragTrap(std::string str);
		void highFivesGuys(void);
};