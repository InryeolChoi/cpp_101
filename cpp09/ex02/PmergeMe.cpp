#include "PmergeMe.hpp"

// orthodox canonical form
PmergeMe::PmergeMe()
{}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	*this = other;	
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other) {}
	return (*this);
}

PmergeMe::~PmergeMe()
{}

// constructor overload
PmergeMe::PmergeMe(int ac, char **av)
{

	for (int i = 1; i < ac; i++)
	{
		int value = std::atoi(av[i]);
		if (value <= 0)
			throw WrongInput();
		vector.push_back(value);
		deque.push_back(value);
		list.push_back(value);
	}
}

// sort algorithm
void PmergeMe::sortVector()
{
	displayBefore(vector);
	clock_t start = clock();




	clock_t finish = clock();
	double result = static_cast<double>(finish - start);
	displayAfter(vector, "vector", result);
}



// member function
template <typename T>
void PmergeMe::displayBefore(const T& container)
{
    typename T::const_iterator it;

	std::cout << "Before: ";
    for (it = container.begin(); it != container.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

template <typename T>
void PmergeMe::displayAfter(const T& container, std::string name, double result)
{
    typename T::const_iterator it;

	std::cout << "After: ";
    for (it = container.begin(); it != container.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

	std::cout << "Time to process a range of " << T.size();
	std::cout << " elements with std::" << name << " : ";
	std::cout << result << " us" << std::endl;
}

// exception
const char *PmergeMe::WrongInput::what() const throw()
{
	return ("Error");
}

