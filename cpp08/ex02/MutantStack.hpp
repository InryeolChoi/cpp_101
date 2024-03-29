#pragma once
#include <iostream>
#include <algorithm>
#include <stack>
#include <list>

template <typename T>
class MutantStack : public std::stack<T, std::deque<T> >
{
	public :
		// orthodox canonical form
		MutantStack() {};

		MutantStack(const MutantStack& other) : std::stack<T, std::deque<T> >(other)
		{
			this->c = other.c;
		};

		MutantStack& operator=(const MutantStack& other) 
		{
			if (this != &other)
				this->c = other.c;
			return (*this);
		}

		~MutantStack(void) {};

		// member function (for iterator)
		typedef typename MutantStack<T>::stack::container_type::iterator iterator;
		iterator begin(void) { return this->c.begin(); }
		iterator end(void) { return this->c.end(); }

		typedef typename MutantStack<T>::stack::container_type::const_iterator const_iterator;
		const_iterator begin(void) const { return (this->c.begin()); }
		const_iterator end(void) const { return (this->c.end()); }

		typedef typename MutantStack<T>::stack::container_type::reverse_iterator reverse_iterator;
		reverse_iterator rbegin(void) { return (this->c.rbegin()); }
		reverse_iterator rend(void) { return (this->c.rend()); }

		typedef typename MutantStack<T>::stack::container_type::const_reverse_iterator const_reverse_iterator;
		const_reverse_iterator rbegin(void) const { return (this->c.rbegin()); }
		const_reverse_iterator rend(void) const { return (this->c.rend()); }
};