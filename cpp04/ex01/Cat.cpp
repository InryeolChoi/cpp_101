#include "Cat.hpp"

// orthodox canonical form
Cat::Cat()
{
	std::cout << "Cat constructor works" << std::endl;
	brain = new Brain();
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
	delete brain;
}

// overriding
void  Cat::makeSound() const
{
	std::cout << "Cat sounds : \"meow~\"" << std::endl;
}