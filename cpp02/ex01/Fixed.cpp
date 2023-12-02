#include "Fixed.hpp"

Fixed::Fixed(const int number)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const float number)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &f)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &f)
{
	std::cout << "Copy assignment operator called" << std::endl;
}

std::ostream &Fixed::operator<<(std::ostream &os, const Fixed &f)
{
	os << f.toFloat();
	return os;
}

float Fixed::toFloat(void) const
{
	return ( (float)this->value / (1 << this->frac_bits) );
}

int Fixed::toInt(void) const
{
	return ( (this->value) >> (this->frac_bits) );
}