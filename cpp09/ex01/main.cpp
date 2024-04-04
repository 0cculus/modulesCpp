#include "RPN.hpp"

bool checkArg(std::string src)
{
	int nbOperators = 0;
	int nbNumbers = 0;

	for (size_t i = 0; i < src.length(); i++)
	{
		if (src[i] == '+' || src[i] == '-' || src[i] == '*' || src[i] == '/')
			nbOperators++;
		else if (std::isdigit(src[i]))
			nbNumbers++;
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
		if (checkArg(av[1]))
			calc.calculate(av[1]);
		else
			std::cout << "invalid amount of operators or numbers in the equation" << std::endl;
	}
	else
		std::cout << "requires an equation" << std::endl;
}
