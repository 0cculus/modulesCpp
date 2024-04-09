#include "PmergeMe.hpp"

bool checkArgs(char** av)
{
	int i = 0;
	while (av[++i])
	{
		int j = -1;
		while (av[i][++j])
		{
			if (!std::isdigit(av[i][j]))
			{
				std::cout << "Error: invalid argument, not a number" << std::endl;
				return (true);
			}
		}
	}
	return (false);
}

int main(int ac, char** av)
{
	if (ac > 1)
	{
		PmergeMe algo;
		int i = 1;
		if (checkArgs(av))
			return (1);
		while (av[i])
		{
			algo.getVc().push_back(atoi(av[i]));
			algo.getDq().push_back(atoi(av[i]));
			i++;
		}
		algo.sorting();
	}
}
