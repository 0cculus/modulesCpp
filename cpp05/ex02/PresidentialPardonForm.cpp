#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string newTarget) : AForm("shrubbery", 145, 137)
{
	
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) : AForm(copy)
{
	(*this) = copy
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& copy)
{
	this->target = copy.getTarget();
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

std::string PresidentialPardonForm::getTarget()
{
	return (this->target);
}

void PresidentialPardonForm::execute(Bureaucrat& const executor) const
{
	if (this->getGradeToExecute() < executor.getGrade())
		throw AForm::GradeTooLowException();
	if (!this->getIsSigned())
		throw std::invalid_argument("Current Shrubbery Form is not signed\n");

}
