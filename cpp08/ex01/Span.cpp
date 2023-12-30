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
	if (this != &other)
	{
		length = other.length;
		vec = other.vec;
	}
	return (*this);
}

Span::~Span()
{}

// constructor overload
Span::Span(unsigned int n) : length(n), vec(std::vector<int>())
{}

// member function
std::size_t Span::getLength() const
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

void Span::randomSampling()
{
	srand(time(NULL));
	for (size_t i = 0; i < length; i++)
		vec.push_back((rand() % 10001) + 1);
}

int	Span::checkNumber(int n)
{
	if (static_cast<size_t>(n) > length || n < 0 || !vec[n])
		throw std::out_of_range("wrong index");
	return (vec[n]);
}

std::size_t Span::shortestSpan() const
{
	if (getLength() < 2 || vec.size() < 2)
		throw NotEnoughSize();

	long tmp_span = std::numeric_limits<int>::max();
	long shortestSpan = std::numeric_limits<int>::max();
	std::vector<int> vec2 = vec;
	std::vector<int>::iterator it;

	std::sort(vec2.begin(), vec2.end());
	for (it = vec2.begin(); it != vec2.end(); it++)
	{
		if (it != vec2.begin())
			tmp_span = *it - *(it - 1);
		shortestSpan = std::min(shortestSpan, tmp_span);
	}
	return static_cast<std::size_t>(shortestSpan);
}

std::size_t Span::longestSpan() const
{
	if (getLength() < 2 || vec.size() < 2)
		throw NotEnoughSize();

	long max = *(std::max_element(vec.begin(), vec.end()));
	long min = *(std::min_element(vec.begin(), vec.end()));
	long longestSpan = max - min;

	return (static_cast<std::size_t>(longestSpan));
}

// exception
const char *Span::VectorIsFull::what() const throw()
{
	return ("vector is full");
}

const char *Span::NotEnoughSize::what() const throw()
{
	return ("vector is not long enough");
}
