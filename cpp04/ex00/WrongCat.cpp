#include "WrongCat.hpp"

// orthodox canonical form
WrongCat::WrongCat()
{
	std::cout << "WrongCat constructor works" << std::endl;
	setType("WrongCat");
}

WrongCat::WrongCat(const WrongCat &other)
{
	*this = other;
}

WrongCat WrongCat::operator=(const WrongCat &other)
{
	if (this != &other)
		this->setType(other.type);
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