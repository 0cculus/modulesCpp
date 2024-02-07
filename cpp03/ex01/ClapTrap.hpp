#ifndef CLAPTRAP_HPP_
# define CLAPTRAP_HPP_

# include <iostream>
# include <string>

class ClapTrap
{
	protected:
		unsigned int attackDmg;
		int energyPoints;
		int hitPoints;
		std::string name;
	public:
		ClapTrap(std::string newName);
		ClapTrap(const ClapTrap& copy);
		ClapTrap& operator=(const ClapTrap& copy);
		virtual ~ClapTrap();

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void setName(std::string newName);
		std::string getName() const;
};

#endif
