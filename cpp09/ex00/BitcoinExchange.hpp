#ifndef BTCEXCHANGE_HPP_
# define BTCEXCHANGE_HPP_

# include <exception>
# include <iostream>
# include <fstream>
# include <string>
# include <list>
# include <map>

# define DATE_VALUE_SEPERATOR 11
# define YEAR_MONTH_SEPERATOR 4
# define MONTH_DAY_SEPERATOR 7

class BitcoinExchange
{
	private:
		std::map<std::string, float> map;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& copy);
		BitcoinExchange& operator=(const BitcoinExchange& copy);
		~BitcoinExchange();
		
		void insertValue(std::string src);
		float btcValueAtDate();
};

#endif
