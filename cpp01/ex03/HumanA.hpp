#ifndef HUMANA_HPP_
# define HUMANA_HPP_

# include <iostream> 
# include <string>
# include "Weapon.hpp"

class HumanA
{
	private:
		std::string name;
		Weapon& wpn;
	public:
		HumanA(std::string name, Weapon& newWpn);
		HumanA(const HumanA& copy);
		HumanA& operator=(const HumanA& copy);
		~HumanA();

		const Weapon& getWeapon() const;
		const std::string& getName() const;
		void setWeapon(Weapon& newWpn);
		void setName(std::string newName);
		void attack();
};

#endif
