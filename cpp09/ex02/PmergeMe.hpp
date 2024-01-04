#pragma once
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <deque>


class PmergeMe
{
	private:
		std::vector<std::pair<int,int> > pair_vec, pair_vec2;
		std::vector<int> vector, mainVec, pendingVec, seq;

		std::deque<std::pair<int,int> > pair_deq, pair_deq2;
		std::deque<int> deque, mainDeq, pendingDeq, seqDeq;
		PmergeMe();

	public:
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();

		// constructor overload
		PmergeMe(int ac, char **av);

		// sort algorithm : vector
		void caseVector();
		void vec_makePair();
		void vec_mergeSort(std::vector<std::pair<int, int> > &vec, int begin, int end);
		void vec_merge(std::vector<std::pair<int, int> > &vec, int begin, int mid, int end);
		void vec_mainWithPending();
		void vec_makeSeq();
		size_t vec_binarySearch(std::vector<int> &array, int num, int low, int high);
		void vec_insertSort();

		// sort algorithm : deque
		void caseDeque();
		void deq_makePair();
		void deq_mergeSort(std::deque<std::pair<int, int> > &deqPair, int begin, int end);
		void deq_merge(std::deque<std::pair<int, int> > &deqPair, int begin, int mid, int end);
		void deq_mainWithPending();
		void deq_makeSeq();
		size_t deq_binarySearch(std::deque<int> &array, int num, int low, int high);
		void deq_insertSort();


		// member function : other
		int	Jacobsthal_number(int i);

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

