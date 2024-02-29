#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern& copy)
{
	*this = copy;
}

Intern& Intern::operator=(const Intern& copy)
{
	(void)copy;
	return (*this);
}

Intern::~Intern()
{
}

static void create(std::string formType)
{
	std::cout << "Intern creates " << formType << std::endl;
}

AForm* Intern::makeForm(std::string formType, std::string formTarget)
{
	std::string form[] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	int val = 9;

	for (int i = 0; i < 3; i++)
	{
		if (form[i] == formType)
			val = i;
	}
	
	switch (val)
	{
		case 0:
			create(formType);
			return(new RobotomyRequestForm(formTarget));
		case 1:
			create(formType);
			return(new PresidentialPardonForm(formTarget));
		case 2:
			create(formType);
			return(new ShrubberyCreationForm(formTarget));
		default:
				throw std::invalid_argument("Invalid form");
	}
	return (NULL);
}
