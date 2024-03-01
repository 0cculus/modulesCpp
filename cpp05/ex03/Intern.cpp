#include "Intern.hpp"

#define MAX_FUNC 3

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

static AForm* newShrub(std::string formTarget) { return (new ShrubberyCreationForm(formTarget)); }

static AForm* newPres(std::string formTarget) { return (new PresidentialPardonForm(formTarget)); }

static AForm* newRob(std::string formTarget) { return(new RobotomyRequestForm(formTarget)); }

AForm* Intern::makeForm(std::string formType, std::string formTarget)
{
	std::string form[MAX_FUNC] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	AForm* (*formRequest[MAX_FUNC])(std::string) = {&newRob, &newPres, &newShrub};

	for (int i = 0; i < MAX_FUNC; i++)
	{
		if (form[i] == formType)
		{
			create(formType);
			return (formRequest[i](formTarget));
		}
	}

	throw std::invalid_argument("Invalid form");
}
