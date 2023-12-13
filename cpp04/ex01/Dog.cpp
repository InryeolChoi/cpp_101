#include "Dog.hpp"

// orthodox canonical form
Dog::Dog() : Animal("Dog"), brain(new Brain())
{
	std::cout << "Dog constructor works" << std::endl;
}

Dog::Dog(const Dog &other) 
	: Animal(other.getType()), brain(new Brain(*(other.brain)))
{}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		this->setType(other.type);
		if (this->brain)
			delete brain;
		brain = new Brain(*(other.brain));
	}
	return (*this);
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Dog destructor works" << std::endl;
}

// overriding
void  Dog::makeSound() const
{
	std::cout << "Dog sounds : \"Bark~\"" << std::endl;
}

Brain *Dog::getBrain() const
{
	return (brain);
}