#include "PmergeMe.hpp"

static double getTime()
{
	static bool setup = true;
	static std::chrono::high_resolution_clock::time_point time;
	std::chrono::duration<double, std::milli> delta;

	if (setup)
	{
		time = std::chrono::high_resolution_clock::now();
		setup = false;
	}
	else
	{
		delta = std::chrono::high_resolution_clock::now() - time;
		setup = true;
	}
	return (delta.count());
}

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

template <typename T>
void PmergeMe::show(T arr)
{
	for (size_t i = 0; i < arr.size(); i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

void PmergeMe::sorting()
{
	double timeVc;
	double timeDq;

	std::cout << "Vector Before: ";
	show(this->vc);
	std::cout << "Double Queue Before: ";
	show(this->dq);

	std::cout << std::endl;

	(void)getTime();
	sort(this->vc, 0, this->vc.size() - 1, this->vc.size() / 2);
	timeVc = getTime();

	(void)getTime();
	sort(this->dq, 0, this->dq.size() - 1, this->dq.size() / 2);
	timeDq = getTime();

	std::cout << "Vector After: ";
	show(this->vc);
	std::cout << "Double Queue After: ";
	show(this->dq);

	std::cout << std::endl;

	std::cout << "Sorting time for " << this->vc.size() << " elements with Vector: " << timeVc << std::endl;
	std::cout << "Sorting time for " << this->dq.size() << " elements with Double Queue: " << timeDq << std::endl;
}
