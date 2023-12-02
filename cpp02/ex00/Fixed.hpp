#pragma once
#include <iostream>

class Fixed
{
	private:
		int value;
		static const int frac_bits;
	public:
		Fixed();
		Fixed(const Fixed &f);
		~Fixed();
		Fixed &operator=(const Fixed &f);
		int getRawBits(void) const;
		void setRawBits(int const raw);
};