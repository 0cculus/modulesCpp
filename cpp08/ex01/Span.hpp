#ifndef SPAN_HPP_
# define SPAN_HPP_

# include <algorithm>
# include <iostream>
# include <vector>
# include <limits.h>

class Span
{
	private:
		size_t size;
		std::vector<int> array;
	public:
		Span(size_t n);
		Span(const Span& copy);
		Span& operator=(const Span& copy);
		~Span();

		int shortestSpan();
		int longestSpan();
		void addNumber(int val);
};

#endif
