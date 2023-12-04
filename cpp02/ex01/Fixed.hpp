#pragma once
#include <cmath>
#include <iostream>

class Fixed
{
	private:
		int value;					// 값
		static const int bits = 8;	// 비트
	public:
		// Orthodox Canonical form
		Fixed();
		Fixed(const Fixed &f);
		Fixed &operator=(const Fixed &f);
		~Fixed();

		// ex00
		int getRawBits(void) const;
		void setRawBits(int const raw);

		// ex01
		Fixed(const int number);
		Fixed(const float number);
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, Fixed const &f);
