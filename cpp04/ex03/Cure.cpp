#include "Cure.hpp"

// orthodox canonical form
Cure::Cure() : AMateria("Cure")
{
	std::cout << "Cure constructor called" << std::endl;
}

Cure::Cure(const Cure &other) : AMateria(other)
{}

Cure &Cure::operator=(const Cure &other)
{
	(void) other;
	return (*this);	
}

Cure::~Cure()
{
	std::cout << "Cure destructor called" << std::endl;
}

// member function
AMateria *Cure::clone(void) const
{
	return (new Cure());
}
