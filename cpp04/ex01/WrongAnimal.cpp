#include "WrongAnimal.hpp"

// Orthodox Canonical form
WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal constructor works" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	*this = other;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	if (this != &other)
		this->setType(other.getType());
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor works" << std::endl;
}

// member function
void WrongAnimal::makeSound() const
{
	std::cout << "(WrongAnimal Sound)" << std::endl;
}

void WrongAnimal::setType(std::string str)
{
	type = str;
}

std::string WrongAnimal::getType() const
{
	return (type);
}