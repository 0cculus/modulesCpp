#ifndef CLAPTRAP_HPP_
# define CLAPTRAP_HPP_

class ClapTrap
{
	private:
		unsigned int hitPoints;
		unsigned int energyPoints;
		unsigned int attackDmg;
	public:
		ClapTrap();
		ClapTrap(unsigned int newHitPoints, unsigned int newEnergyPoints, unsigned int newAttackDmg);
		ClapTrap(const ClapTrap& copy);
		ClapTrap& operator=(const ClapTrap& copy);

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif
