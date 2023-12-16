#include "WrongCat.hpp"

// orthodox canonical form
WrongCat::WrongCat() : WrongAnimal(), brain(new Brain())
{
	std::cout << "WrongCat constructor works" << std::endl;
	setType("WrongCat");
}

WrongCat::WrongCat(const WrongCat &other) :
	WrongAnimal(other), brain(new Brain(*(other.brain)))
{}

WrongCat WrongCat::operator=(const WrongCat &other)
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

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor works" << std::endl;
}

// overriding
void  WrongCat::makeSound() const
{
	std::cout << "WrongCat sounds : \"(none)\"" << std::endl;
}

// member function
Brain *WrongCat::getBrain() const
{
	return (brain);
}