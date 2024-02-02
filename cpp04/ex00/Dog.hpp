#ifndef DOG_HPP_
# define DOG_HPP_

# include <iostream>
# include <string>
# include "Animal.hpp"

class Dog : public Animal
{
	private:
	public:
		Dog();
		Dog(std::string newType);
		Dog(const Dog& copy);
		Dog& operator=(const Dog& copy);
		~Dog();

		void makeSound();
};

#endif
