#include "Cat.hpp"

// orthodox canonical form
Cat::Cat()
{
	setType("Cat");
}

Cat::Cat(const Cat &other)
{}

Cat Cat::operator=(const Cat &other)
{
	if (this != &other)
		this->setType(other.type);
	return (*this);
}

Cat::~Cat()
{}

// overriding
void  Cat::makeSound()
{
	std::cout << "meow~" << std::endl;
}