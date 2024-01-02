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
		list.push_back(value);
	}
}

// sort algorithm : vector
void PmergeMe::caseVector()
{
	displayBefore(vector);
	clock_t start = clock();
	mergeVector();
	insertVector();
	clock_t finish = clock();
	double result = static_cast<double>(finish - start);
	displayAfter(vector, "vector", result);
}

void PmergeMe::mergeVector()
{
	for (size_t i = 0; i < vector.size(); i += 2)
	{
		if (vector[i] < vector[i + 1] && vector[i + 1])
		{
			int tmp = vector[i + 1];
			vector[i + 1] = vector[i];
			vector[i] = tmp;
		}
	}

	for (size_t i = 0; i < vector.size(); i += 2)
	{
		if (i % 2 == 0)
			mainVec.push_back(vector[i]);
		else
			pendingVec.push_back(vector[i]);
	}
}

void PmergeMe::insertVector()
{
	std::vector<int> jn;
	int idx = 0;

	for (size_t i = 0; i < pendingVec.size(); i++)
	{
		if (i == 0)
			jn.push_back(0);
		else if (i == 1)
			jn.push_back(1);
		else
			jn.push_back(jn[i - 1] + jn[i - 2]);
	}

	for (size_t i = 0; i < pendingVec.size(); i++)
	{
		int x = pendingVec[jn[i]];
		
	}
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

	std::cout << "Time to process a range of " << container.size();
	std::cout << " elements with std::" << name << " : ";
	std::cout << result << " us" << std::endl;
}

// exception
const char *PmergeMe::WrongInput::what() const throw()
{
	return ("Error");
}
