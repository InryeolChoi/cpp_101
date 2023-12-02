#pragma once
#include <cmath>
#include <iostream>

class Fixed
{
	private:
		int value;
		static const int frac_bits = 8;
	public:
		Fixed(const int number);
		Fixed(const float number);
		Fixed(const Fixed &f);
		~Fixed();
		Fixed &operator=(const Fixed &f);
		std::ostream &operator<<(std::ostream &os, const Fixed &f);
		float	toFloat(void) const;
		int		toInt(void) const;
};