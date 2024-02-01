#ifndef HUMANB_HPP_
# define HUMANB_HPP_

# include <iostream> 
# include <string>
# include "Weapon.hpp"

class HumanB
{
	private:
		std::string name;
		Weapon* wpn;
	public:
		HumanB(std::string name);
		HumanB(const HumanB& copy);
		HumanB& operator=(const HumanB& copy);
		~HumanB();

		Weapon* getWeapon() const;
		std::string getName() const;
		void setWeapon(Weapon& newWpn);
		void setName(std::string newName);
		void attack();
};

#endif
