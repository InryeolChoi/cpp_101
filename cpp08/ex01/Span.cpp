#include "Span.hpp"

// orthodox canonical form
Span::Span() : length(0), vec(std::vector<int>())
{}

Span::Span(const Span &other)
{
	*this = other;
}

Span &Span::operator=(const Span &other)
{
	if (this != &other) {}
	return (*this);
}

Span::~Span()
{}

// constructor overload
Span::Span(unsigned int n) : length(n), vec(std::vector<int>())
{}

// member function
std::size_t Span::getLength()
{
	return (length);
}

void Span::addNumber(int n)
{
	if (vec.size() < length)
		vec.push_back(n);
	else
		throw VectorIsFull();
}

std::size_t Span::shortestSpan()
{
	if (getLength() <= 2)
		throw NotEnoughSize();
	return (*(std::max_element(vec.begin(), vec.end())) - *(std::min_element(vec.begin(), vec.end())));
}

std::size_t Span::longestSpan()
{
	if (getLength() <= 2)
		throw NotEnoughSize();
		long ret = LONG_MAX;
	int prev;
	std::vector<int> tmp = vec;

	std::sort(tmp.begin(), tmp.end());
	for (std::vector<int>::iterator iter = tmp.begin(); iter != tmp.end(); iter++) 
	{
		if (iter == tmp.begin()) 
			prev = *iter;
		else
		{
			if (ret > *iter - prev)
				ret = *iter - prev;
			prev = *iter;
		}
	}
	return static_cast<std::size_t>(ret);
}

const char *Span::VectorIsFull::what() const throw()
{
	return ("vector is full");
}

const char *Span::NotEnoughSize::what() const throw()
{
	return ("vector is not long enough");
}