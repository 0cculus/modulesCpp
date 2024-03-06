#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe& copy)
{
	(*this) = copy;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& copy)
{
	(void)copy;
	return (*this);
}

PmergeMe::~PmergeMe()
{
}

std::vector<int>& PmergeMe::getVc()
{
	return (this->vc);
}

std::deque<int>& PmergeMe::getDq()
{
	return (this->dq);
}

void PmergeMe::sorting(std::string type)
{
	if (type == "vc")
		sort(this->vc, 0, this->vc.size() - 1, this->vc.size() / 2);
	else if (type == "dq")
		sort(this->dq, 0, this->dq.size() - 1, this->dq.size() / 2);
}
