#ifndef MUTANT_HPP_
# define MUTANT_HPP_

# include <stack>
# include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
	private:

	public:
		MutantStack() : std::stack<T>() {};
		MutantStack(const MutantStack& copy) { (*this) = copy; };
		MutantStack& operator=(const MutantStack& copy) { std::stack<T>::operator=(copy); };
		~MutantStack() {};

		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator revIterator;

		iterator begin() { return (this->c.begin()); };
		iterator end() { return (this->c.end()); };
		revIterator rbegin() { return (this->c.rbegin()); };
		revIterator rend() { return (this->c.rend()); };
};

#endif
