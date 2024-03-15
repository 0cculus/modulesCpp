#include "Converter.hpp"

Converter::Converter() : i(0), c(0), f(0.0f), d(0.0), special(false)
{
}

Converter::Converter(const Converter& copy)
{
	(*this) = copy;
}

Converter& Converter::operator=(const Converter& copy)
{
	this->d = copy.getDouble();
	this->f = copy.getFloat();
	this->c = copy.getChar();
	this->i = copy.getInt();
	return (*this);
}

Converter::~Converter()
{
}

void Converter::convert(std::string type, std::string src)
{
	if (type == "int")
	{
		this->i = atoi(src.c_str());
		std::cout << this->i << std::endl;
	}
	else if (type == "char")
	{
		this->c = static_cast<char>(src[0]);
		std::cout << this->c << std::endl;
	}
	else if (type == "float")
	{
		this->f = atof(src.c_str());
		std::cout << this->f << std::endl;
	}
	else if (type == "double")
	{
		this->d = static_cast<double>(atof(src.c_str()));
		std::cout << this->d << std::endl;
	}
	else if (type == "sfloat")
	{
		this->special = true;
		this->f = atof(src.c_str());
	}
	else if (type == "sdouble")
	{
		this->special = true;
		this->d = static_cast<double>(atof(src.c_str()));
	}
	convertChar(type);
	convertInt(type);
	convertFloat(type);
	convertDouble(type);
}

void Converter::convertDouble(std::string type)
{
	std::cout.setf(std::ios::fixed, std::ios::floatfield);
	std::cout.precision(1);
	if (type == "int")
		 std::cout << "double: " << static_cast<double>(this->i) << std::endl;
	else if (type == "char")
		 std::cout << "double: " << static_cast<double>(this->c) << std::endl;
	else if (type == "float" || type == "sfloat")
		 std::cout << "double: " << static_cast<double>(this->f) << std::endl;
	else if (type == "double" || type == "sdouble")
		std::cout << "double: " << this->d << std::endl;
}

void Converter::convertFloat(std::string type)
{
	std::cout.setf(std::ios::fixed, std::ios::floatfield);
	std::cout.precision(1);
	if (type == "char")
		std::cout << "float: " << static_cast<float>(this->c) << "f" << std::endl;
	else if (type == "int")
		std::cout << "float: " << static_cast<float>(this->i) << "f" << std::endl;
	else if (type == "double")
		std::cout << "float: " << static_cast<float>(this->d) << "f" << std::endl;
	else if (type == "sdouble" && this->special)
		std::cout << "float: " << static_cast<float>(this->d) << "f" << std::endl;
	else if (type == "float" || type == "sfloat")
		std::cout << "float: " << this->f << "f" << std::endl;
}

void Converter::convertChar(std::string type)
{
	if (type == "int")
	{
		if (isprint(this->i))
			std::cout << "char: " << static_cast<char>(this->i) << std::endl;
		else
			std::cout << "char: N/A" << std::endl;
	}
	else if (type == "float")
	{
		if (this->f >= (float)INT_MIN && this->f >= (float)INT_MAX)
		{
			int converted = static_cast<int>(this->f);
			if (isascii(converted))
				std::cout << "char: " << converted << std::endl;
		}
		else
			std::cout << "char: N/A" << std::endl;
	}
	else if (type == "double")
	{
		if (this->d >= (double)INT_MIN && this->d >= (double)INT_MAX)
		{
			int converted = static_cast<int>(this->d);
			if (isascii(converted))
				std::cout << "char: " << converted << std::endl;
		}
		else
			std::cout << "char: N/A" << std::endl;
	}
	else if (type == "sdouble" || type == "sfloat")
			std::cout << "char: N/A" << std::endl;
	else if (type == "char")
		std::cout << "char: " << this->c << std::endl;
}

void Converter::convertInt(std::string type)
{
	if (type == "float")
	{
		if (this->f >= (float)INT_MIN && this->f >= (float)INT_MAX)
			std::cout << "char: " << static_cast<int>(this->f) << std::endl;
		else
			std::cout << "char: N/A" << std::endl;
	}
	else if (type == "double")
	{
		if (this->d >= (double)INT_MIN && this->d >= (double)INT_MAX)
			std::cout << "int: " << static_cast<int>(this->d) << std::endl;
		else
			std::cout << "int: N/A" << std::endl;
	}
	else if (type == "sdouble" || type == "sfloat")
		std::cout << "int: N/A" << std::endl;
	else if (type == "char")
		std::cout << "int: " << static_cast<int>(this->c) << std::endl;
	else if (type == "int")
		std::cout << "int: " << this->i << std::endl;
}

double Converter::getDouble() const
{
	return (this->d);
}

float Converter::getFloat() const
{
	return (this->f);
}

char Converter::getChar() const
{
	return (this->c);
}

int Converter::getInt() const
{
	return (this->i);
}
