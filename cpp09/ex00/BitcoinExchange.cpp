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

	date = src.substr(0, sepIndex);
	value = static_cast<float>(std::stod(src.substr(sepIndex + 1, src.length() - sepIndex)));
	this->map.insert(std::pair<std::string, float>(date, value));
}

float BitcoinExchange::btcValueAtDate()
{
	float value = 0.0f;
	return (value);
}
