#include "Weapon.hpp"

Weapon::Weapon()
{
	this->type = "";
}

Weapon::Weapon(std::string newType)
{
	this->type = newType;
}

Weapon::Weapon(const Weapon& copy)
{
	this->setType(copy.getType());
	(*this) = copy;
}

Weapon& Weapon::operator=(const Weapon& copy)
{
	this->setType(copy.getType());
	return (*this);
}

Weapon::~Weapon()
{
}

std::string Weapon::getType() const
{
	return (this->type);
}

void Weapon::setType(std::string newType)
{
	this->type = newType;
}

