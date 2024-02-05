#ifndef ANIMAL_HPP_
# define ANIMAL_HPP_

# include <iostream>
# include <string>

class Animal
{
	protected:
		std::string type;
		Animal();
		Animal(std::string newType);
		Animal(const Animal& copy);
	public:
		Animal& operator=(const Animal& copy);
		virtual ~Animal();

		virtual void makeSound() = 0;
		const std::string& getType() const;
		void setType(std::string newType);
};

#endif
