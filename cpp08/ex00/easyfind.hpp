#pragma once
#include <iostream>
#include <vector>
#include <deque>

template <typename T>
typename T::iterator easyfind(T &container, int value)
{
	typename T::iterator it;
	for (it = container.begin(); it != container.end(); ++it) {
		if (*(it) == value)
			return it;
	}
	throw std::out_of_range("not found");
}