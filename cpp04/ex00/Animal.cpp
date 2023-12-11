#include "Animal.hpp"

// Orthodox Canonical form
Animal::Animal() : type("none")
{}

Animal::Animal(const Animal &other)
{
	*this = other;
}

Animal &Animal::operator=(const Animal &other)
{
	if (this != &other)
		this->type = other.type;
	return (*this);
}

Animal::~Animal()
{}

// member function
void Animal::makeSound()
{
	std::cout << "(none)" << std::endl;
}

void Animal::setType(std::string str)
{
	type = str;
}

std::string Animal::getType()
{
	return type;
}