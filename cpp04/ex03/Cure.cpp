#include "Cure.hpp"

// orthodox canonical form
Cure::Cure() : AMateria("Cure")
{}

Cure::Cure(const Cure &other) : AMateria(other)
{}

Cure &Cure::operator=(const Cure &other)
{
	(void) other;
	return (*this);	
}

Cure::~Cure()
{}

// member function
AMateria *Cure::clone(void) const
{
	return (new Cure());
}

void Cure::use(ICharacter &target)
{
	if (type == "Cure")
	{
		std::cout << "* heals " << target.getName();
		std::cout << "'s wounds *" << std::endl;
	}
}
