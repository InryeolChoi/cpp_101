#include "Ice.hpp"

// orthodox canonical form
Ice::Ice() : AMateria("Ice")
{
	std::cout << "Ice constructor called" << std::endl;
}

Ice::Ice(const Ice &other) : AMateria(other)
{}

Ice &Ice::operator=(const Ice &other)
{
	(void) other;	
	return (*this);	
}

Ice::~Ice()
{
	std::cout << "Ice destructor called" << std::endl;
}

// member function
AMateria *Ice::clone(void) const
{
	return (new Ice());
}
