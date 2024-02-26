#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string newTarget) : AForm("robotomy", 72, 45)
{
	
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) : AForm(copy)
{
	(*this) = copy
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy)
{
	this->target = copy.getTarget();
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

std::string RobotomyRequestForm::getTarget()
{
	return (this->target);
}

void RobotomyRequestForm::execute(Bureaucrat& const executor) const
{
	if (this->getGradeToExecute() < executor.getGrade())
		throw AForm::GradeTooLowException();
	if (!this->getIsSigned())
		throw std::invalid_argument("Current Shrubbery Form is not signed\n");

	
}
