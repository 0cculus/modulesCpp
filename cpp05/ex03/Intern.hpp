#ifndef INTERN__HPP__
# define INTERN__HPP__

# include "AForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
	private:
	public:
		Intern();
		Intern(const Intern& copy);
		Intern& operator=(const Intern& copy);
		~Intern();

		AForm* makeForm(std::string formType, std::string formTarget);
};

#endif
