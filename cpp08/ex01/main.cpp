#include "Span.hpp"

int main()
{
	// given example
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;	
	std::cout << std::endl;

	// my own example
	Span sp2 = Span(1000);
	sp2.randomSampling();
	std::cout << sp2.checkNumber(10) << std::endl;
	std::cout << sp2.shortestSpan() << std::endl;
	std::cout << sp2.longestSpan() << std::endl;
}