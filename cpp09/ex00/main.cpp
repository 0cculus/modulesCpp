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
	int month = std::stoi(src.substr(YEAR_MONTH_SEPERATOR, YEAR_MONTH_SEPERATOR - MONTH_DAY_SEPERATOR));
	int day = std::stoi(src.substr(MONTH_DAY_SEPERATOR, MONTH_DAY_SEPERATOR - src.length()));
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

void parseInput(std::string src)
{
	size_t pos = src.find('|');
	if (pos != std::string::npos)
	{
		if (pos == DATE_VALUE_SEPERATOR)
		{
			if (pos != src.length() - 1)
				(void)static_cast<float>(std::stod(src.c_str() + pos + 1));
			if (!validDateFormat(src, pos - 1))
				throw std::invalid_argument("invalid date format");
		}
	}
	else
		throw std::invalid_argument("invalid input syntax\ncorrect syntax:\"YYYY-MM-DD | [0-1000]\"");
}

int main(int ac, char** av)
{
	if (ac == 2)
	{
		//std::list<std::string> list;

		std::string line;
		std::fstream data("./data.csv", std::ios::in);
		BitcoinExchange btc;
		if (data.fail())
		{
			std::cout << "no data given" << std::endl;
			return (1);
		}
		while (std::getline(data, line))
			std::cout << line << std::endl;
		std::fstream request(av[1], std::ios::in);
		try
		{
			while (std::getline(request, line))
				parseInput(line);
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
