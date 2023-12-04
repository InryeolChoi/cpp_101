#pragma once
#include <iostream>

class Fixed
{
	private:
		int value;					// 값
		static const int bits = 8;	// 비트
	public:
		Fixed();
		Fixed(const Fixed &f);
		~Fixed();
		Fixed &operator=(const Fixed &f);
		int getRawBits(void) const;
		void setRawBits(int const raw);
};