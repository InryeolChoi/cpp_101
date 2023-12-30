#include "MutantStack.hpp"

int main(void)
{
	// const 없는 경우 (given example)
	std::cout << "< example 1 >" << std::endl;
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << "top : " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "size : " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	std::cout << std::endl;

	// list와의 비교 (itearator가 잘 돌아가나?)
	std::cout << "< example 2 : list와의 비교 >" << std::endl;
	std::list<int> a;

	a.push_back(5);
	a.push_back(17);
	std::cout << "back : " << a.back() << std::endl;
	a.pop_back();
	std::cout << "size : " << a.size() << std::endl;
	a.push_back(3);
	a.push_back(5);
	a.push_back(737);
	a.push_back(0);

	std::list<int>::iterator it_list = a.begin();
	std::list<int>::iterator it_list2 = a.end();
	++it_list;
	--it_list;
	while (it_list != it_list2)
		std::cout << *(it_list++) << std::endl;
	std::cout << std::endl;

	// const 있는 케이스
	std::cout << "< example 3 : const >" << std::endl;
	const MutantStack<int> mstack2(mstack);
	for (MutantStack<int>::const_iterator it3 = mstack2.begin(); it3 != mstack2.end(); ++it3)
	{
		std::cout << *it3 << " ";
		// *(it3) = 10;
	}
	std::cout << std::endl << std::endl;

	// reverse case
	std::cout << "< example 4 : reverse >" << std::endl;
	MutantStack<int> mstack3(mstack);
	MutantStack<int>::reverse_iterator r_it = mstack3.rbegin();
	MutantStack<int>::reverse_iterator r_ite = mstack3.rend();
	++r_it;
	--r_it;
	while (r_it != r_ite)
		std::cout << *(r_it++) << " ";
	std::cout << std::endl;

	return 0;
}