#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string newName)
{
	this->energyPoints = 10;
	this->hitPoints = 10;
	this->attackDmg = 0;
	this->name = newName;
	std::cout << "ClapTrap " << this->name << ": Hey, check me out everybody! I'm dancin', I'm dancin'!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy)
{
	this->energyPoints = copy.energyPoints;
	this->hitPoints = copy.hitPoints;
	this->attackDmg = copy.attackDmg;
	this->name = copy.name;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& copy)
{
	this->energyPoints = copy.energyPoints;
	this->hitPoints = copy.hitPoints;
	this->attackDmg = copy.attackDmg;
	this->name = copy.name;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->name << ": I can see... the code..." << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->energyPoints > 0 && this->hitPoints > 0)
	{
		this->energyPoints--;
		std::cout << this->name << ": That looks like it hurts! (dealt " << this->attackDmg << " damage to " << target << ")" << std::endl;
	}
	else
		std::cout << this->name << ": Rrrrrgh...this isn't working!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoints > 0)
	{
		this->hitPoints -= amount;
		std::cout << this->name << ": My robotic flesh! AAHH! (hit for " << amount << " hit points)" << std::endl;
	}
	else
		std::cout << this->name << ": Oh my God, I'm leaking! I think I'm leaking! Ahhhh, I'm leaking! There's oil everywhere!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoints > 0 && this->hitPoints > 0)
	{
		this->energyPoints--;
		std::cout << this->name << ": Good as new, I think. Am I leaking? (repaired for " << amount << " hit points)" << std::endl;
		this->hitPoints += amount;
	}
	else
		std::cout << this->name << ": Rrrrrgh...this isn't working!" << std::endl;
}

void ClapTrap::setName(std::string newName)
{
	this->name = newName;
}

std::string ClapTrap::getName() const
{
	return (this->name);
}
