#include "Span.hpp"

// orthodox canonical form
Span::Span()
{}

Span::Span(const Span &other)
{
	*this = other;
}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{

	}
	return (*this);
}

Span::~Span()
{}

// constructor overload
Span::Span(unsigned int n) : length(n)
{

}


// member function
void Span::addNumber(int n)
{
	if (vec.size() < length)
		vec.push_back(n);
	throw VectorIsFull();
}

int Span::shortestSpan()
{
}

int Span::longestSpan()
{

}

const char *Span::VectorIsFull::what() const throw()
{
	return ("vector is full");
}