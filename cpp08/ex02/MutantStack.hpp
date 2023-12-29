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

		typedef typename MutantStack<T>::stack::container_type::iterator const_iterator;
		const_iterator cbegin(void) const { return (this->c.cbegin()); }
		const_iterator cend(void) const { return (this->c.cend()); }

		typedef typename MutantStack<T>::stack::container_type::iterator reverse_iterator;
		reverse_iterator rbegin(void) { return (this->c.rbegin()); }
		reverse_iterator rend(void) { return (this->c.rend()); }

		typedef typename MutantStack<T>::stack::container_type::iterator const_reverse_iterator;
		const_reverse_iterator crbegin(void) const { return (this->c.crbegin()); }
		const_reverse_iterator crend(void) const { return (this->c.crend()); }
};