#include "Zombie.hpp"

int main()
{
	Zombie a("Harold");
	Zombie b("Larry");
	Zombie* c;
	c = newZombie("Agrid");

	randomChump("Rory");

	a.announce();
	b.announce();
	c->announce();

	delete c;
}
