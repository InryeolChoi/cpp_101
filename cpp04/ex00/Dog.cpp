#include "Dog.hpp"

// orthodox canonical form
Dog::Dog()
{
	setType("Dog");
}

Dog::Dog(const Dog &other)
{
	*this = other;
}

Dog Dog::operator=(const Dog &other)
{
	if (this != &other)
		this->setType(other.type);
	return (*this);
}

Dog::~Dog()
{}

// overriding
void  Dog::makeSound()
{
	std::cout << "Bark~" << std::endl;
}