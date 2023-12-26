#pragma once
#include <iostream>

// template function
template <typename T>
void iter(T *arr, size_t arr_len, void (*fun)(T &))
{
	if (arr == NULL || fun == NULL)
		return ;
	for (size_t i = 0; i < arr_len; i++)
		fun(arr[i]);
}