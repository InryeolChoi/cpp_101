#include "Fixed.hpp"

// Orthodox Canonical form
Fixed::Fixed() {}

Fixed::Fixed(const Fixed &f)
{
	value = f.getRawBits();
}

Fixed::~Fixed()
{
}

Fixed &Fixed::operator=(const Fixed &f)
{
	if (this != &f)
		this->value = f.getRawBits();
	return (*this);
}

// ex00
int Fixed::getRawBits() const
{
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
	value = number << this->bits;
}

Fixed::Fixed(const float number)
{
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

// ex02, 비교 연산자, 6개
bool Fixed::operator>(Fixed const &f) const
{
	if (this->getRawBits() > f.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator<(Fixed const &f) const
{
	if (this->getRawBits() < f.getRawBits())
		return (true);
	return (false);	
}

bool Fixed::operator>=(Fixed const &f) const
{
	if (this->getRawBits() >= f.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator<=(Fixed const &f) const
{
	if (this->getRawBits() <= f.getRawBits())
		return (true);
	return (false);	
}

bool Fixed::operator==(Fixed const &f) const
{
	if (this->getRawBits() == f.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator!=(Fixed const &f) const
{
	if (this->getRawBits() != f.getRawBits())
		return (true);
	return (false);
}

// ex02, 산수 연산자, 4개
Fixed	Fixed::operator+(Fixed const &f) const
{
	Fixed result(this->getRawBits() + f.getRawBits());
	return (result);
}

Fixed	Fixed::operator-(Fixed const &f) const
{
	Fixed result(this->getRawBits() - f.getRawBits());
	return (result);
}

Fixed	Fixed::operator*(Fixed const &f) const
{
	Fixed result(this->getRawBits() * f.getRawBits());
	return (result);
}

Fixed	Fixed::operator/(Fixed const &f) const
{
	Fixed result(this->getRawBits() / f.getRawBits());
	return (result);
}

// ex02, 증감 연산자
Fixed &Fixed::operator++(void) // 전위, 증가
{
	this->value += 1;
	return (*this);
}

Fixed &Fixed::operator--(void) // 전위, 감소
{
	this->value -= 1;
	return (*this);
}

Fixed Fixed::operator++(int) // 후위, 증가
{
	Fixed result = *this;

	(this->value) += 1;
	return (result);
}

Fixed Fixed::operator--(int) // 후위, 감소
{
	Fixed result = *this;

	(this->value) -= 1;
	return (result);
}


// ex02, min과 max
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)\
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}
