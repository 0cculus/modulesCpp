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
	public:
		Converter();
		Converter(const Converter& copy);
		Converter& operator=(const Converter& copy);
		~Converter();

		void convert(std::string src);
		void convertFromDouble(double src);
		void convertFromFloat(float src);
		void convertFromChar(char src);
		void convertFromInt(int src);

		double getDouble();
		float getFloat();
		char getChar();
		int getInt();
};
