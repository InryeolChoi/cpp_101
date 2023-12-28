#pragma once
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
	public :
		// orthodox canonical form
		MutantStack(void) {};
		MutantStack(const MutantStack& obj) {*this = obj;};
		MutantStack& operator=(const MutantStack& obj) {*this = obj; return (*this);}
		~MutantStack(void) {};

		// member function
};