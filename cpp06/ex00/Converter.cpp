#include "Converter.hpp"

Converter() : i(0), c(0), f(0.0f), d(0.0), special(false)
{
}

Converter(const Converter& copy)
{
	(*this) = copy;
}

Converter& operator=(const Converter& copy)
{
	this->d = copy.getDouble();
	this->f = copy.getFloat();
	this->c = copy.getChar();
	this->i = copy.getInt();
	return (*this);
}

~Converter()
{
}

void convert(std::string src)
{
	if (src == "int")
	else if (src == "char")
	else if (src == "float")
	else if (src == "double")
	else if (src == "sfloat")
	{
		this->special = true;
	}
	else if (src == "sdouble")
	{
	}
}

void convertDouble(double src)
{
	if ()
		std::cout << "char: '" << src << "'" << std::endl;
	else
		std::cout << "char: N/A" << std::endl;


	std::cout << "double: " << src << std::endl;
}

void convertFloat(float src)
{

}

void convertChar(char src)
{
}

void convertInt(int src)
{
}

double getDouble()
{
	return (this->d);
}

float getFloat()
{
	return (this->f);
}

char getChar()
{
	return (this->c);
}

int getInt()
{
	return (this->i);
}
