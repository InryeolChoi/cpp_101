#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	protected:
		const unsigned int init_hp;
		const unsigned int init_ep;
		const unsigned int init_ad;

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