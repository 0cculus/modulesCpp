#include "PmergeMe.hpp"

bool checkArgs(char** av)
{
	int i = -1;
	while (av[++i])
	{
		int j = -1;
		while (av[i][++j])
			if (av[i][j] < '0' || av[i][j] > '9')
				return (true);
	}
	return (false);
}

int main(int ac, char** av)
{
	if (ac > 1)
	{
		PmergeMe algo;
		int i = 0;
		if (checkArgs(av))
			return (1);
		while (av[i])
		{
			algo.getVc().push_back(atoi(av[i]));
			algo.getDq().push_back(atoi(av[i]));
			i++;
		}
	}
}
