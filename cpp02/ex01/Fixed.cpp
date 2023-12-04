#include "Fixed.hpp"

// Orthodox Canonical form
Fixed::Fixed() {}

Fixed::Fixed(const Fixed &f)
{
	std::cout << "Copy constructor called" << std::endl;
	value = f.getRawBits();
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &f)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &f)
		this->value = f.getRawBits();
	return (*this);
}

// ex00
int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

// << 오버로딩
std::ostream &operator<<(std::ostream &out, Fixed const &f)
{
	out << f.toFloat();
	return (out);
}

// ex01
Fixed::Fixed(const int number)
{
	std::cout << "int constructor called" << std::endl;
	value = number << this->bits;
}

Fixed::Fixed(const float number)
{
	std::cout << "float constructor called" << std::endl;
	value = roundf(number * (1 << bits));
}

float Fixed::toFloat(void) const
{
	return ( (float)this->value / (1 << this->bits) );
}

int Fixed::toInt(void) const
{
	return ( (this->value) >> (this->bits) );
}
