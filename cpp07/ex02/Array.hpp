#ifndef ARRAY_HPP_
# define ARRAY_HPP_

# include <iostream>

template <typename T>
class Array
{
	private:
		size_t sz;
		T* array;
	public:
		Array();
		Array(const size_t n);
		Array(const Array<T>& copy);
		~Array();

		Array<T>& operator=(const Array<T>& copy);
		T& operator[](const size_t index) const;

		size_t size() const;
};

#include "Array.tpp"

#endif
