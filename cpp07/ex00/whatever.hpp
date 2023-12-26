#pragma once
#include <iostream>

// template function
template <typename T>
void swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

template <typename X>
X min(X &a, X &b)
{
	if (a < b)
		return (a);
	return (b);
}

template <typename U>
U max(U &a, U &b)
{
	if (a < b)
		return (b);
	return (a);
}
