#include "Dog.hpp"

// orthodox canonical form
Dog::Dog()
{
	std::cout << "Dog constructor works" << std::endl;
	brain = new Brain();
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
{
	std::cout << "Dog destructor works" << std::endl;
	delete brain;
}

// overriding
void  Dog::makeSound() const
{
	std::cout << "Dog sounds : \"Bark~\"" << std::endl;
}