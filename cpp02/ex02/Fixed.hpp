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

		// ex02, 비교 연산자, 6개
		bool	operator>(Fixed const &f) const;
		bool	operator<(Fixed const &f) const;
		bool	operator>=(Fixed const &f) const;
		bool	operator<=(Fixed const &f) const;
		bool	operator==(Fixed const &f) const;
		bool	operator!=(Fixed const &f) const;

		// ex02, 산수 연산자, 4개
		Fixed	operator+(Fixed const &f) const;
		Fixed	operator-(Fixed const &f) const;
		Fixed	operator*(Fixed const &f) const;
		Fixed	operator/(Fixed const &f) const;

		// ex02, 증감 연산자, 4개
		Fixed	&operator++(void);		// 전위, 증가
		Fixed	&operator--(void);		// 전위, 감소
		Fixed	operator++(int n); 		// 후위, 증가
		Fixed	operator--(int n); 		// 후위, 감소

		// ex02, min과 max, 4개
		static Fixed &min(Fixed &a, Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &min(Fixed const &a, Fixed const &b);
		static const Fixed &max(Fixed const &a, Fixed const &b);
};

std::ostream &operator<<(std::ostream &out, Fixed const &f);
