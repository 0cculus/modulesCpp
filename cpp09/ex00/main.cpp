#include "BitcoinExchange.hpp"

bool validDateFormat(std::string src, size_t end)
{
	for (size_t i = 0; i < end; i++)
	{
		if (std::isdigit(src[i]))
			continue;
		if (src[i] == '-' && (i == YEAR_MONTH_SEPERATOR || i == MONTH_DAY_SEPERATOR))
			continue;
		else
			return (false);
	}
	std::map<int, int> dayPerMonth;
	int month = std::stoi(src.substr(YEAR_MONTH_SEPERATOR + 1, YEAR_MONTH_SEPERATOR - MONTH_DAY_SEPERATOR));
	int day = std::stoi(src.substr(MONTH_DAY_SEPERATOR + 1, MONTH_DAY_SEPERATOR - src.length()));
	int year = std::stoi(src.substr(0, YEAR_MONTH_SEPERATOR)); 
	dayPerMonth[1] = 31;
	if (year % 4)
		dayPerMonth[2] = 28;
	else
		dayPerMonth[2] = 29;
	dayPerMonth[3] = 31;
	dayPerMonth[4] = 30;
	dayPerMonth[5] = 31;
	dayPerMonth[6] = 30;
	dayPerMonth[7] = 31;
	dayPerMonth[8] = 31;
	dayPerMonth[9] = 30;
	dayPerMonth[10] = 31;
	dayPerMonth[11] = 30;
	dayPerMonth[12] = 31;
	if (day < 1 || month < 1 || month > 12 || year < 1 || day > dayPerMonth[month])
		return (false);
	return (true);
}

bool isAllNumbers(std::string src)
{
	for (size_t i = 0; i < src.length(); i++)
		if (!isdigit(src[i]))
			return (false);
	return (true);
}

void parseInput(std::string src, std::list<std::string>& list)
{
	float res = 0.0f;
	size_t pos = src.find('|');

	if (pos != std::string::npos)
	{
		if (pos == DATE_VALUE_SEPERATOR)
		{
			if (pos != src.length() - 1)
			{
				if (isAllNumbers(src.c_str() + pos + 1))
					list.push_back("Error: invalid number");
				else
					res = static_cast<float>(std::stod(src.c_str() + pos + 1));
				if (res < 0.0f || res > 1000.0f)
				{
					list.push_back("Error: invalid amount of coins");
					return ;
				}
				if (!validDateFormat(src, pos - 1))
				{
					list.push_back("Error: invalid date format");
					return ;
				}
				list.push_back(src);
				return ;
			}
		}
	}
	list.push_back("Error: invalid input syntax\ncorrect syntax:\"YYYY-MM-DD | [0-1000]\"");
}

int main(int ac, char** av)
{
	if (ac == 2)
	{
		std::string line;
		BitcoinExchange bex;
		std::list<std::string> list;
		std::fstream data("./data.csv", std::ios::in);

		if (data.fail() || data.peek() == EOF)
		{
			std::cout << "no data given" << std::endl;
			return (1);
		}
		while (std::getline(data, line))
			bex.insertValue(line);

		std::fstream request(av[1], std::ios::in);
		
		if (request.fail() || request.peek() == EOF)
		{
			std::cout << "no input given" << std::endl;
			return (1);
		}
		try
		{
			while (std::getline(request, line))
				parseInput(line, list);
			while (!list.empty())
			{
				bex.btcValueFromInput(list.front());
				list.pop_front();
			}
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	else 
		std::cout << "invalid arguments" << std::endl;
	return (0);
}
