#include "Span.hpp"

Span::Span(size_t n) : size(n)
{
}

Span::Span(const Span& copy)
{
	(*this) = copy;
}

Span& Span::operator=(const Span& copy)
{
	this->array = copy.array;
	this->size  = copy.size;
	return (*this);
}

Span::~Span()
{
}

int Span::shortestSpan()
{
	if (this->array.size() < 2)
		std::invalid_argument("Error: not enough values");
	std::sort(this->array.begin(), this->array.end());
	int shortest = INT_MAX;
	for (size_t i = 0; i < this->array.size() - 1; i++)
	{
		int current = std::abs(this->array[i + 1] - this->array[i]);
		if (current < shortest)
			shortest = current;
		if (current == 0)
			return (0);
	}
	return (shortest);
}

int Span::longestSpan()
{
	if (this->array.size() < 2)
		std::invalid_argument("Error: not enough values");
	std::sort(this->array.begin(), this->array.end());
	return (std::abs(*(this->array.end() - 1) - *(this->array.begin())));
}

void Span::addNumber(int val)
{
	if (this->array.size() < this->size)
		this->array.push_back(val);
	else
		throw std::invalid_argument("Error: exceeds container's range");
}
