#ifndef DOG_HPP_
# define DOG_HPP_

# include <iostream>
# include <string>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain* brain;
	public:
		Dog();
		Dog(std::string newType);
		Dog(const Dog& copy);
		Dog& operator=(const Dog& copy);
		~Dog();

		void makeSound();
		Brain* getBrain();
};

#endif
