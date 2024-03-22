#ifndef EASY_HPP_
# define EASY_HPP_

# include <iterator>

template <typename T>
typename T::iterator easyfind(T array, int toFind)
{
	typename T::iterator itr = std::find(array.begin(), array.end(), toFind);
	if (itr == array.end())
		throw std::invalid_argument("argument not found");
	return (itr);
}

#endif
