#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat base constructor called" << std::endl;
}

WrongCat::WrongCat(std::string newType) : WrongAnimal(newType)
{
	std::cout << "WrongCat overlaod constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& copy) : WrongAnimal(copy)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& copy)
{
	std::cout << "WrongCat assignment operator called" << std::endl;
	this->setType(copy.getType());
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound()
{
}

