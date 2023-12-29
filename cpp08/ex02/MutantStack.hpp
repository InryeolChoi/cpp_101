#pragma once
#include <iostream>
#include <algorithm>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public :
		// orthodox canonical form
		MutantStack(void) {};
		MutantStack(const MutantStack& obj) {*this = obj;};
		MutantStack& operator=(const MutantStack& obj) {*this = obj; return (*this);}
		~MutantStack(void) {};

		// member function (for iterator)
		typedef typename MutantStack<T>::stack::container_type::iterator iterator;
		iterator begin(void) { return this->c.begin(); }
		iterator end(void) { return this->c.end(); }
};