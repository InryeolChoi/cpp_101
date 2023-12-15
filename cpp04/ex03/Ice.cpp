#include "Ice.hpp"

// orthodox canonical form
Ice::Ice() : AMateria("Ice")
{}

Ice::Ice(const Ice &other) : AMateria(other)
{}

Ice &Ice::operator=(const Ice &other)
{
	(void) other;	
	return (*this);	
}

Ice::~Ice()
{}

// member function
AMateria *Ice::clone(void) const
{
	return (new Ice());
}

void Ice::use(ICharacter &target)
{
	if (type == "Ice")
	{
		std::cout << "* shoots an ice bolt at ";
		std::cout << target.getName() << " *";
		std::cout << std::endl;
	}
}
