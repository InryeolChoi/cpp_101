#include "AAnimal.hpp"

// Orthodox Canonical form
AAnimal::AAnimal() : type("none")
{
	std::cout << "Animal constructor works" << std::endl;
}

AAnimal::AAnimal(const AAnimal &other)
{
	*this = other;
}

AAnimal &AAnimal::operator=(const AAnimal &other)
{
	if (this != &other)
		this->setType(other.type);
	return (*this);
}

AAnimal::~AAnimal()
{
	std::cout << "Animal destructor works" << std::endl;
}

// member function
AAnimal::AAnimal(std::string str)
{
	type = str;
}

void AAnimal::setType(std::string str)
{
	type = str;
}

std::string AAnimal::getType() const
{
	return type;
}