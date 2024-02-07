#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ScavTrap c1("c1");
	FragTrap c2("c2");

	c2.highFivesGuys();
	c1.attack(c2.getName());
	c1.beRepaired(21);
	c1.beRepaired(21);
	c1.beRepaired(21);
	c1.beRepaired(21);
	c1.beRepaired(21);
	c1.beRepaired(21);
	c1.beRepaired(21);
	c1.beRepaired(21);
	c1.beRepaired(21);
	c1.beRepaired(21);
	c1.beRepaired(21);
	c1.beRepaired(21);
	c1.beRepaired(21);
	c1.beRepaired(21);
	c1.beRepaired(21);
	c1.beRepaired(21);
	c1.beRepaired(21);
	c1.beRepaired(21);
	c1.beRepaired(21);
	c1.beRepaired(21);
	c1.beRepaired(21);
	c1.beRepaired(21);
	c2.takeDamage(21);
	c2.attack(c1.getName());
	c2.beRepaired(12);
	c2.beRepaired(12);
	c2.highFivesGuys();
}
