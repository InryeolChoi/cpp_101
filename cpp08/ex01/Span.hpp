#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

class Span
{
	private:
		Span();
		std::size_t length;
		std::vector<int> vec;

	public:
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();

		// constructor overload
		Span(unsigned int n);

		// member function
		std::size_t getLength() const;
		void addNumber(int n);
		std::size_t shortestSpan() const;
		std::size_t longestSpan() const;
		void randomSampling();	// 무제한 addNumber();
		int	checkNumber(int n);

		// exception
		class VectorIsFull : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class NotEnoughSize : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};