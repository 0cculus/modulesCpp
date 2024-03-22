# include <vector>
# include <iostream>
# include "easyfind.hpp"

int main()
{
	std::vector<int> list;

	for (int i = 1; i < 10; i++)
		list.push_back(42 * i);

	{
		try
		{
			std::vector<int>::iterator it = easyfind(list, 42);
			std::cout << *it << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		try
		{
			std::vector<int>::iterator it = easyfind(list, 168);
			std::cout << *it << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		try
		{
			std::vector<int>::iterator it = easyfind(list, 160);
			std::cout << *it << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return (0);
}
