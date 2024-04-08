#include "RPN.hpp"

bool checkArg(std::string src)
{
	int nbOperators = 0;
	int nbNumbers = 2;

	if (src.length() > 2 && !std::isdigit(src[0]) && !std::isdigit(src[1]))
		return (false);
	for (size_t i = 2; i < src.length(); i++)
	{
		if (src[i] == '+' || src[i] == '-' || src[i] == '*' || src[i] == '/')
			nbOperators++;
		else if (std::isdigit(src[i]))
			nbNumbers++;
		else
			return (false);
	}
	if (nbOperators != nbNumbers - 1)
		return (false);
	return (true);
}

int main(int ac, char** av)
{
	if (ac == 2)
	{
		RPN calc;
		std::string arg = av[1];

		arg.erase(remove_if(arg.begin(), arg.end(), isspace), arg.end());
		if (checkArg(arg))
		{
			try
			{
				calc.calculate(arg);
			}
			catch (std::exception& e)
			{
				std::cout << e.what() << std::endl;
			}
		}
		else
			std::cout << "invalid amount of operators or numbers in the equation" << std::endl;
	}
	else
		std::cout << "requires an equation" << std::endl;
}
