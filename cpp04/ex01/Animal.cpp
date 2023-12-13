#include "Animal.hpp"

// Orthodox Canonical form
Animal::Animal() : type("none")
{
	std::cout << "Animal constructor works" << std::endl;
}

Animal::Animal(const Animal &other)
{
	*this = other;
}

Animal &Animal::operator=(const Animal &other)
{
	if (this != &other)
		this->setType(other.type);
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal destructor works" << std::endl;
}

// member function
Animal::Animal(std::string str)
{
	type = str;
}

void Animal::makeSound() const
{
	std::cout << "Animal sounds : (none)" << std::endl;
}

void Animal::setType(std::string str)
{
	type = str;
}

std::string Animal::getType() const
{
	return type;
}