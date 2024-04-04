#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy)
{
	(*this) = copy;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& copy)
{
	this->map = copy.map;
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::insertValue(std::string src)
{
	size_t sepIndex = src.find(',');
	std::string date;
	float value;

	if (src == "date,exchange_rate")
		return ;
	date = src.substr(0, sepIndex);
	value = static_cast<float>(std::stod(src.substr(sepIndex + 1, src.length() - sepIndex)));
	this->map.insert(std::pair<std::string, float>(date, value));
}

void BitcoinExchange::btcValueFromInput(std::string src)
{
	if (src.find("Error:") == std::string::npos)
	{
		int beginMonth = std::stoi(this->map.begin()->first.substr(YEAR_MONTH_SEPERATOR + 1, YEAR_MONTH_SEPERATOR - MONTH_DAY_SEPERATOR));
		int srcMonth = std::stoi(src.substr(YEAR_MONTH_SEPERATOR + 1, YEAR_MONTH_SEPERATOR - MONTH_DAY_SEPERATOR));
		int beginDay = std::stoi(this->map.begin()->first.substr(MONTH_DAY_SEPERATOR + 1, MONTH_DAY_SEPERATOR - src.length()));
		int srcDay = std::stoi(src.substr(MONTH_DAY_SEPERATOR + 1, MONTH_DAY_SEPERATOR - src.length()));
		int beginYear = std::stoi(this->map.begin()->first.substr(0, YEAR_MONTH_SEPERATOR)); 
		int srcYear = std::stoi(src.substr(0, YEAR_MONTH_SEPERATOR)); 

		if (srcYear < beginYear || (srcYear == beginYear && srcMonth < beginMonth) || (srcYear == beginYear && srcMonth == beginMonth && srcDay < beginDay))
		{
			std::cout << "Error: too early" << std::endl;
			return ;
		}
		size_t pos = src.find('|');
		std::string date = src.substr(0, pos - 1);
		float amount = static_cast<float>(std::stod(src.c_str() + pos + 1));

		std::map<std::string, float>::iterator value;
		value = this->map.lower_bound(date);
		if (value != this->map.begin())
			value--;
		std::cout << value->first << " => " << amount << " = " << (value->second * amount) << std::endl;
	}
	else
		std::cout << src << std::endl;
}
