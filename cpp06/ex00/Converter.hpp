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

		void convert(std::string src);
		void convertDouble(double src);
		void convertFloat(float src);
		void convertChar(char src);
		void convertInt(int src);

		double getDouble();
		float getFloat();
		char getChar();
		int getInt();
};
