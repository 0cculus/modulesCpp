#ifndef ANIMAL_HPP_
# define ANIMAL_HPP_

# include <iostream>
# include <string>

class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		Animal(std::string newType);
		Animal(const Animal& copy);
		Animal& operator=(const Animal& copy);
		virtual ~Animal();

		virtual void makeSound();
		const std::string& getType() const;
		void setType(std::string newType);
};

#endif
