#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		// orthodox canonical form
		Ice();
		Ice(const Ice &other);
		Ice &operator=(const Ice &other);
		~Ice();

		// member function
		AMateria *clone() const;
		void use();
};