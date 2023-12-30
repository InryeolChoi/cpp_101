#include "Span.hpp"

int main()
{
	// given example
	std::cout << "< example 1 >" << std::endl;
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << "Shortest span of sp : " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span of sp : " << sp.longestSpan() << std::endl;	
	std::cout << std::endl;

	// my own example
	std::cout << "< example 2 >" << std::endl;
	Span sp2 = Span(10000);
	sp2.randomSampling();
	try 
	{
		std::cout << "sp2[10] : " << sp2.checkNumber(10) << std::endl;
		std::cout << "sp2[0] : " << sp2.checkNumber(0) << std::endl;

		// std::cout << "sp2[1001] : " << sp2.checkNumber(1001) << std::endl;
		// std::cout << "sp2[-1] : " << sp2.checkNumber(-1) << std::endl;
	}
	catch(std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "Shortest span of sp2 : " << sp2.shortestSpan() << std::endl;
	std::cout << "Longest span of sp2 : " << sp2.longestSpan() << std::endl;
}