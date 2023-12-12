#include "Cat.hpp"

// orthodox canonical form
Cat::Cat()
{
	std::cout << "Cat constructor works" << std::endl;
	setType("Cat");
}

Cat::Cat(const Cat &other)
{
	*this = other;
}

Cat Cat::operator=(const Cat &other)
{
	if (this != &other)
		this->setType(other.type);
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor works" << std::endl;
}

// overriding
void  Cat::makeSound() const
{
	std::cout << "meow~" << std::endl;
}