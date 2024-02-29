#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string newTarget) : AForm("robotomy", 72, 45)
{
	this->target = newTarget;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) : AForm(copy)
{
	(*this) = copy;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy)
{
	this->target = copy.getTarget();
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

std::string RobotomyRequestForm::getTarget() const
{
	return (this->target);
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	if (!this->getIsSigned())
		throw std::invalid_argument("Current Robotomy Form is not signed\n");
	if (this->getGradeToExecute() < executor.getGrade())
		throw AForm::GradeTooHighException();

	std::srand(std::time(nullptr));
	if (std::rand() % 2)
		std::cout << "Congratulations, " << this->getTarget() << "has been robotomized! The surgery was a success!" << std::endl;
	else
		std::cout << "Unfortunately, " << this->getTarget() << "'s robotomy surgery has failed. Better luck next time!" << std::endl;
}
