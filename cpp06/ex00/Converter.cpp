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

void convert(std::string type, std::string src)
{
	if (src == "int")
		this->i = atoi(src);
	else if (src == "char")
		this->c = static_cast<char>(src);
	else if (src == "float")
		this->f = atof(src);
	else if (src == "double")
		this->d = static_cast<double>(atof(src));
	else if (src == "sfloat")
	{
		this->special = true;
		this->f = atof(src);
	}
	else if (src == "sdouble")
	{
		this->special = true;
		this->d = static_cast<double>(atof(src));
	}
	convertChar(type);
	convertInt(type);
	convertFloat(type);
	convertDouble(type);
}

void convertDouble(std::string type)
{
	if (type == "int")
		 std::cout << "double: " << static_cast<double>(this->i) << std::endl;
	else if (type == "char")
		 std::cout << "double: " << static_cast<double>(this->c) << std::endl;
	else if (type == "float" || type == "sfloat")
		 std::cout << "double: " << static_cast<double>(this->f) << std::endl;
	else if (type == "double" || type == "sdouble")
		std::cout << "double: " << this->d << std::endl;
}

void convertFloat(std::string type)
{
	if (type == "char")
		std::cout << "float: " << static_cast<float>this->c << std::endl;
	else if (type == "int")
		std::cout << "float: " << static_cast<float>this->i << std::endl;
	else if (type == "double")
		std::cout << "float: " << static_cast<float>this->d << std::endl;
	else if (type == "sdouble" && this->special)
		std::cout << "float: " << static_cast<float>this->d << std::endl;
	else if (type == "float" || type == "sfloat")
		std::cout << "float: " << this->f << std::endl;
}

void convertChar(std::string type)
{
	if (type == "int")
	{
		if (std::isascii(this->i))
			std::cout << "char: " << static_cast<char>(this->i) << std::endl;
		else
			std::cout << "char: N/A" << std::endl;
	}
	else if (type == "float")
	{
		if (this->f >= (float)INT_MIN && this->f >= (float)INT_MAX)
		{
			int converted = static_cast<int>(this->f);
			if (std::isascii(converted))
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
			if (std::isascii(converted))
				std::cout << "char: " << converted << std::endl;
		}
		else
			std::cout << "char: N/A" << std::endl;
	}
	else if (type == "sdouble" || type == "sfloat")
			std::cout << "char: N/A" << std::endl;
	else if (type = "char")
		std::cout << "char: " << this->c << std::endl;
}

void convertInt(std::string type)
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
