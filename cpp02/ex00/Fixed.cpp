#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Constructor called" << std::endl;
	this->rawVal = 0;
}

Fixed::Fixed(const Fixed& copy)
{
	std::cout << "Copy constructor called" << std::endl;
	(*this) = copy;
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
