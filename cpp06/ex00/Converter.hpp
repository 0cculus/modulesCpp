#ifndef CONVERTER_HPP_
# define CONVERTER_HPP_

# include <iostream>
# include <string>

class Converter
{
	private:
		int i;
		char c;
		float f;
		double d;
		bool special;
	public:
		Converter();
		Converter(const Converter& copy);
		Converter& operator=(const Converter& copy);
		~Converter();

		void convert(std::string type, std::string src);
		void convertDouble(std::string type);
		void convertFloat(std::string type);
		void convertChar(std::string type);
		void convertInt(std::string type);

		double getDouble();
		float getFloat();
		char getChar();
		int getInt();
};
