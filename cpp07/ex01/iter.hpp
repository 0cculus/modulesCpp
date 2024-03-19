#ifndef ITER_HPP_
# define ITER_HPP_

#include <iostream>

template <typename T>
void iter(T* arr, size_t size, T func(T param))
{
	for (size_t i = 0; i < size; i++)
		func(arr[i]);
}

template <typename T, typename PTRFN>
void iter(T* arr, size_t size, PTRFN func)
{
	for (size_t i = 0; i < size; i++)
		func(arr[i]);
}

#endif
