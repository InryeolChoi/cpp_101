#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		// orthodox canonical form
		Cure();
		Cure(const Cure &other);
		Cure &operator=(const Cure &other);
		~Cure();

		// member function
		AMateria *clone() const;
		void use();
};