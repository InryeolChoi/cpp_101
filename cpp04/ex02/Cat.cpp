#include "Cat.hpp"

// orthodox canonical form
Cat::Cat() : AAnimal("Cat"), brain(new Brain())
{
	std::cout << "Cat constructor works" << std::endl;
}

Cat::Cat(const Cat &other) 
	: AAnimal(other.getType()), brain(new Brain(*(other.brain)))
{}

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		this->setType(other.getType());
		if (this->brain)
			delete brain;
		brain = new Brain(*(other.brain));
	}
	return *this;
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Cat destructor works" << std::endl;
}

// overriding
void  Cat::makeSound() const
{
	std::cout << "Cat sounds : \"meow~\"" << std::endl;
}

Brain *Cat::getBrain() const
{
	return (brain);
}