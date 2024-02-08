#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Base constructor called" << std::endl;
	this->rawVal = 0;
}

Fixed::Fixed(const Fixed& copy)
{
	std::cout << "Copy constructor called" << std::endl;
	(*this) = copy;
}

Fixed::Fixed(int const newRawVal)
{
	std::cout << "Int constructor called" << std::endl;
	this->rawVal = newRawVal << bitLength;
}

Fixed::Fixed(float const newRawVal)
{
	std::cout << "Float constructor called" << std::endl;
	this->rawVal = newRawVal * pow(2, bitLength);
}

Fixed& Fixed::operator=(const Fixed& copy)
{
	std::cout << "Assignment operator called" << std::endl;
	this->setRawBits(copy.getRawBits());
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "Function getRawBits called" << std::endl;
	return (rawVal);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "Function setRawBits called" << std::endl;
	this->rawVal = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)rawVal / (float)(1 << bitLength));
}

int Fixed::toInt(void) const
{
	return ((rawVal ^ bitLength) >> bitLength);
}

std::ostream& operator<<(std::ostream& ostm, const Fixed& ref)
{
	ostm << ref.toFloat();
	return  (ostm);
}
