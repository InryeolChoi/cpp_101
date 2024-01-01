#pragma once
#include <iostream>
#include <cstdlib>
#include <vector>
#include <list>
#include <deque>

class PmergeMe
{
	private:
		std::vector<int> vector;
		std::deque<int> deque;
		std::list<int> list;
		PmergeMe();

	public:
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();

		// constructor overload
		PmergeMe(int ac, char **av);

		// sort algorithm
		void sortVector();
		void sortDeque();
		void sortList();

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

