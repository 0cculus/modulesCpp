#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string newTarget) : AForm("presidential", 25, 5)
{
	this->target = newTarget;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) : AForm(copy)
{
	(*this) = copy;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& copy)
{
	this->target = copy.getTarget();
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

std::string PresidentialPardonForm::getTarget() const
{
	return (this->target);
}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
	if (this->getGradeToExecute() < executor.getGrade())
		throw AForm::GradeTooHighException();
	if (!this->getIsSigned())
		throw std::invalid_argument("Current Presidential Form is not signed\n");

	std::cout << "Greetings members of this nation! I am proud to inform you that " << this->getTarget() << " has been pardonned by our greatest president Zaphod Beeblebrox!" << std::endl;
}
