#include "Zombie.hpp"

int main()
{
	Zombie* horde = zombieHorde(12, "doom");

	for (int i = 0; i < 12; i++)
		horde[i].announce();

	delete[] horde;
}
