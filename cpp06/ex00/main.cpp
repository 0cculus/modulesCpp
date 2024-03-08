//#include "Converter.hpp"
# include <iostream>
# include <string>

bool isAlpha(char src)
{
	if (src >= 'a' && src <= 'z')
		return (true);
	return (false);
}

bool isNum(char src)
{
	if (src >= '0' && src <= '9')
		return (true);
	return (false);
}

std::string checkArg(std::string arg)
{
	std::string type;

	if (arg == "nanf" || arg == "+inff" || arg == "-inff")
		type = "float";
	else if (arg == "nan" || arg == "+inf" || arg == "-inf")
		type = "double";
	else if (arg.length() > 1)
	{
		for (size_t i = 0; i < arg.length(); i++)
		{
			if (arg[i] < '0' || arg[i] > '9')
				if (arg[i] != '.' && arg[i] != 'f' && arg[i] != '-')
					throw std::invalid_argument("Bad input");
		}
		if (arg.find(".") != std::string::npos)
		{
			if (arg.find("f") != std::string::npos)
				type = "float";
			else
				type = "double";
		}
		else
			type = "int";
	}
	else if (arg.length() == 1)
	{
		if (isAlpha(arg[0]))
			type = "char";
		else if (isNum(arg[0]))
			type = "int";
	}
	else 
		throw std::invalid_argument("Bad input");
	return (type);
}

int main(int ac, char** av)
{
	if (ac == 2)
	{
		std::string input = av[1];
		if (!input.empty())
		{
			try
			{
				std::string type = checkArg(input);
				std::cout << type << std::endl;
				//convert(input);
			}
			catch (std::exception& e)
			{
				std::cout << e.what() << std::endl;
			}
		}
	}
	else
		std::cout << "invalid amount of args" << std::endl;
}