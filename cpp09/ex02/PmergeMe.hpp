#pragma once
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <list>

class PmergeMe
{
	private:
		std::vector<int> vector, mainVec, pendingVec;
		std::list<int> list;
		PmergeMe();

	public:
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();

		// constructor overload
		PmergeMe(int ac, char **av);

		// sort algorithm
		void caseVector();
		void mergeVector();
		void insertVector();

		// template function
		template <typename T>
		void displayBefore(const T& container);

		template <typename T>
		void displayAfter(const T& container, std::string name, double result);

		// exception
		class WrongInput : public std::exception
		{
			const char *what() const throw();
		};
};

