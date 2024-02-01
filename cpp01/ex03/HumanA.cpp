#include "HumanA.hpp"

HumanA::HumanA(std::string newName, Weapon& newWpn) : wpn(newWpn)
{
	this->name = newName;
}

HumanA::HumanA(const HumanA& copy) : wpn(copy.wpn)
{
	this->setName(copy.getName());
	(*this) = copy;
}

HumanA& HumanA::operator=(const HumanA& copy)
{
	this->wpn = copy.wpn;
	this->setName(copy.getName());
	return (*this);
}

HumanA::~HumanA()
{
}

const Weapon& HumanA::getWeapon() const
{
	return (this->wpn);
}

const std::string& HumanA::getName() const
{
	return (this->name);
}

void HumanA::setWeapon(Weapon& newWpn)
{
	this->wpn = newWpn;
}

void HumanA::setName(std::string newName)
{
	this->name = newName;
}

void HumanA::attack()
{
	std::cout << this->getName() << " attacks with their " << this->wpn.getType() << std::endl;
}

