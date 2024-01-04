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
		// 숫자 외 문자 검사
		std::string str(av[i]);
		for (size_t idx = 0; idx < str.size(); idx++)
		{
			if (!isdigit(str[idx]))
				throw WrongInput();
		}
	
		// 범위 체크 (int)
		double d = std::atof(av[i]);
		if (d > std::numeric_limits<int>::max() || d < 0)
			throw WrongInput();

		// 삽입
		vector.push_back(std::atoi(av[i]));
		deque.push_back(std::atoi(av[i]));
	}
}

// sort algorithm : vector
void PmergeMe::caseVector()
{
	displayBefore(vector);
	clock_t start = clock();
	vec_makePair();										// 짝 만들기
	vec_mergeSort(pair_vec, 0, pair_vec.size() - 1);	// 합병정렬 해주기
	vec_mainWithPending();								// main과 pending으로 나누기
	vec_makeSeq(); 										// 야곱스털 수 기반 배열
	vec_insertSort();									// 정렬
	clock_t finish = clock();
	double result = static_cast<double>(finish - start);
	displayAfter(mainVec, "vector", result);
}

void PmergeMe::vec_makePair()
{
	int	pair_size = vector.size() / 2;
	int i = 0;

	while (pair_size != 0)
	{
		if (vector[i] < vector[i + 1] && vector[i + 1])
		{
			int tmp = vector[i + 1];
			vector[i + 1] = vector[i];
			vector[i] = tmp;
		}
		pair_vec.push_back(std::make_pair(vector[i], vector[i + 1]));
		pair_vec2.push_back(std::make_pair(vector[i], vector[i + 1]));
		i += 2;
		pair_size--;
	}
}

void PmergeMe::vec_mergeSort(std::vector<std::pair<int, int> > &pairs, int begin, int end)
{
	int	mid;
	if (begin >= end)
		return ;
	mid = (begin + end) / 2;

	vec_mergeSort(pairs, begin, mid);
	vec_mergeSort(pairs, mid + 1, end);
	vec_merge(pairs, begin, mid, end);
}

void PmergeMe::vec_merge(std::vector<std::pair<int, int> > &pairs, int begin, int mid, int end)
{
	int i = begin, j = mid + 1, k = begin;
	while (i <= mid && j <= end)
	{
		if (pairs[i].first <= pairs[j].first)
			this->pair_vec2[k++] = pairs[i++];
		else
			this->pair_vec2[k++] = pairs[j++];
	}
	if (i > mid)
	{
		for (int idx = j; idx <= end; idx++)
			this->pair_vec2[k++] = pairs[idx];
	}
	else
	{
		for (int idx = i; idx <= mid; idx++)
			this->pair_vec2[k++] = pairs[idx];
	}

	// 최종 삽입
	for (int idx = begin; idx <= end; idx++)
		pairs[idx] = this->pair_vec2[idx];
}

void PmergeMe::vec_mainWithPending()
{
	for (size_t i = 0; i < pair_vec.size(); i++)
	{
		mainVec.push_back(pair_vec[i].first);
		pendingVec.push_back(pair_vec[i].second);
	}
}

void PmergeMe::vec_makeSeq()
{
	// 야콥스탈 수 만들기
	int idx = 0;
	std::vector<int> jn;
	while (1)
	{
		int x = Jacobsthal_number(idx);
		if (x > static_cast<int>(pendingVec.size()))
			break;
		jn.push_back(x);
		idx++;
	}

	// 출력 수열 (seq_order)
	int last_pos = 0, value = 0, pos = 0;
	size_t i = 0;

	while (i < pendingVec.size())
	{
		if (i == 0 || i == 1)
		{
			i++;
			continue;
		}
		value = jn[i];
		seq.push_back(value);
		pos = value - 1;
		while (pos > last_pos)
		{
			seq.push_back(pos);
			pos--;
		}
		last_pos = value;
		i++;
	}

	value = pendingVec.size();
	while (value > last_pos)
	{
		seq.push_back(value);
		value--;
	}
}

void PmergeMe::vec_insertSort()
{
	std::vector<int>::iterator it;
	size_t add = 0, pos = 0;
	int number;

	for (it = seq.begin(); it < seq.end(); it++)
	{
		// 해당 숫자의 위치 찾기
		number = pendingVec[*it - 1];
		pos = vec_binarySearch(mainVec, number, 0, (*it + add));

		// 위치에 따른 값 삽입
		mainVec.insert(mainVec.begin() + pos, number);
		add++;
	}

	// 전체 숫자 갯수가 홀수인 경우, 맨 마지막 원소 넣어주기
	if (vector.size() % 2 == 1)
	{
		number = vector[vector.size() - 1];
		pos = vec_binarySearch(mainVec, number, 0, mainVec.size() - 1);

		mainVec.insert(mainVec.begin() + pos, number);
	}
}

size_t PmergeMe::vec_binarySearch(std::vector<int> &array, int num, int low, int high)
{
	int mid;
	while (low <= high)
	{
		mid = low + (high - low) / 2;
		if (num == array[mid])
			return (mid);
		if (num > array[mid])
			low = mid + 1;
		else
			high = mid - 1;
	}
	if (num > array[mid])
		return (mid + 1);
	else
		return (mid);
}


/* sort algorithm : Deque */
void PmergeMe::caseDeque()
{
	displayBefore(deque);
	clock_t start = clock();
	deq_makePair();
	deq_mergeSort(pair_deq, 0, pair_deq.size() - 1);
	deq_mainWithPending();
	deq_makeSeq();
	deq_insertSort();
	clock_t finish = clock();
	double result = static_cast<double>(finish - start);
	displayAfter(mainDeq, "Deque", result);
}

void PmergeMe::deq_makePair()
{
	int	pair_size = deque.size() / 2;
	int i = 0;

	while (pair_size != 0)
	{
		if (deque[i] < deque[i + 1] && deque[i + 1])
		{
			int tmp = deque[i + 1];
			deque[i + 1] = deque[i];
			deque[i] = tmp;
		}
		pair_deq.push_back(std::make_pair(deque[i], deque[i + 1]));
		pair_deq2.push_back(std::make_pair(deque[i], deque[i + 1]));
		i += 2;
		pair_size--;
	}
}

void PmergeMe::deq_mergeSort(std::deque<std::pair<int, int> > &deqPair, int begin, int end)
{
	int	mid;
	if (begin >= end)
		return ;
	mid = (begin + end) / 2;

	deq_mergeSort(deqPair, begin, mid);
	deq_mergeSort(deqPair, mid + 1, end);
	deq_merge(deqPair, begin, mid, end);
}

void PmergeMe::deq_merge(std::deque<std::pair<int, int> > &deqPair, int begin, int mid, int end)
{
	int i = begin, j = mid + 1, k = begin;
	while (i <= mid && j <= end)
	{
		if (deqPair[i].first <= deqPair[j].first)
			this->pair_deq2[k++] = deqPair[i++];
		else
			this->pair_deq2[k++] = deqPair[j++];
	}
	if (i > mid)
	{
		for (int idx = j; idx <= end; idx++)
			this->pair_deq2[k++] = deqPair[idx];
	}
	else
	{
		for (int idx = i; idx <= mid; idx++)
			this->pair_deq2[k++] = deqPair[idx];
	}

	// 최종 삽입
	for (int idx = begin; idx <= end; idx++)
		deqPair[idx] = this->pair_deq2[idx];
}

void PmergeMe::deq_mainWithPending()
{
	for (size_t i = 0; i < pair_deq.size(); i++)
	{
		mainDeq.push_back(pair_deq[i].first);
		pendingDeq.push_back(pair_deq[i].second);
	}
}

void PmergeMe::deq_makeSeq()
{
	// 야콥스탈 수 만들기
	int idx = 0;
	std::deque<int> jn;
	while (1)
	{
		int x = Jacobsthal_number(idx);
		if (x > static_cast<int>(pendingDeq.size()))
			break;
		jn.push_back(x);
		idx++;
	}

	// 출력 수열 (seq_order)
	int last_pos = 0, value = 0, pos = 0;
	size_t i = 0;

	while (i < pendingDeq.size())
	{
		if (i == 0 || i == 1)
		{
			i++;
			continue;
		}
		value = jn[i];
		seqDeq.push_back(value);
		pos = value - 1;
		while (pos > last_pos)
		{
			seqDeq.push_back(pos);
			pos--;
		}
		last_pos = value;
		i++;
	}

	value = pendingDeq.size();
	while (value > last_pos)
	{
		seqDeq.push_back(value);
		value--;
	}
}

void PmergeMe::deq_insertSort()
{
	std::deque<int>::iterator it;
	size_t add = 0, pos = 0;
	int number;

	for (it = seqDeq.begin(); it < seqDeq.end(); it++)
	{
		// 해당 숫자의 위치 찾기
		number = pendingDeq[*it - 1];
		pos = deq_binarySearch(mainDeq, number, 0, (*it + add));

		// 위치에 따른 값 삽입
		mainDeq.insert(mainDeq.begin() + pos, number);
		add++;
	}

	// 전체 숫자 갯수가 홀수인 경우, 맨 마지막 원소 넣어주기
	if (vector.size() % 2 == 1)
	{
		number = vector[vector.size() - 1];
		pos = deq_binarySearch(mainDeq, number, 0, mainDeq.size() - 1);

		mainDeq.insert(mainDeq.begin() + pos, number);
	}

}

size_t PmergeMe::deq_binarySearch(std::deque<int> &deq, int num, int low, int high)
{
	int mid;
	while (low <= high)
	{
		mid = low + (high - low) / 2;
		if (num == deq[mid])
			return (mid);
		if (num > deq[mid])
			low = mid + 1;
		else
			high = mid - 1;
	}
	if (num > deq[mid])
		return (mid + 1);
	else
		return (mid);
}

// member function : others
int	PmergeMe::Jacobsthal_number(int i)
{
	if (i == 0)
		return (0);
	else if (i == 1)
		return (1);
	else
		return Jacobsthal_number(i - 1) + 2 * Jacobsthal_number(i - 2);
}

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
