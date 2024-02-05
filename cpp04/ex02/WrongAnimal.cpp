#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal base constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string newType) : type(newType)
{
	std::cout << "WrongAnimal overlaod constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy) : type(copy.type)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& copy)
{
	std::cout << "WrongAnimal assignment operator called" << std::endl;
	this->setType(copy.getType());
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

void WrongAnimal::makeSound()
{
	std::cout << "Wrong sounds or something..." << std::endl;
}

const std::string& WrongAnimal::getType() const
{
	return (this->type);
}

void WrongAnimal::setType(std::string newType)
{
	this->type = newType;
}

