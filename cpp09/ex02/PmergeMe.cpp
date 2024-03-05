#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe& copy)
{
}

PmergeMe& PmergeMe::operator=(const PmergeMe& copy)
{
}

PmergeMe::~PmergeMe()
{
}

void sorting(std::string type)
{
	if (type == "ls")
		mergeinsertsort(this->ls, 0, this->ls.size() - 1);
	else if (type == "dq")
		mergeinsertsort(this->dq, 0, this->dq.size() - 1);
}
