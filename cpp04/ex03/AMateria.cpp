#include "AMateria.hpp"

// Orthodox Canonical form
AMateria::AMateria() : type()
{}

AMateria::AMateria(AMateria const &other) : type(other.getType())
{
	*this = other;
}

AMateria &AMateria::operator=(AMateria const &other)
{
	if (this != &other)
		this->setType(other.getType());
	return *this;
}

AMateria::~AMateria()
{}


// others & member function
AMateria::AMateria(std::string const &type) : type(type)
{}

std::string const &AMateria::getType() const
{
	return (type);
}

void AMateria::setType(std::string str)
{
	type = str;
}

void AMateria::use(ICharacter &target)
{
	(void) target;
}