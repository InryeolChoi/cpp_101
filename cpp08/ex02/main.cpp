#include "MutantStack.hpp"
#include <vector>

int main(void)
{
	// const 없는 경우 (given example)
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;
	mstack.pop();

	std::cout << mstack.size() << std::endl;
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

	// const 있는 케이스
	const MutantStack<int> mstack2(mstack);
	MutantStack<int>::const_iterator it2 = mstack2.begin();
	MutantStack<int>::const_iterator ite2 = mstack2.end();
	while (it2 != ite2)
		std::cout << *(it2++) << std::endl;

	for (MutantStack<int>::const_iterator it3 = mstack2.begin(); it3 != mstack2.end(); ++it3)
	{
		std::cout << *it3 << " ";
		// *(it3) = 10;
	}
	std::cout << std::endl;
	return 0;
}