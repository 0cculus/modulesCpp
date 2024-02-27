#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string newTarget) : AForm("shrubbery", 145, 137)
{
	this->target = newTarget;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : AForm(copy)
{
	(*this) = copy;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy)
{
	this->target = copy.getTarget();
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

std::string ShrubberyCreationForm::getTarget() const
{
	return (this->target);
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	if (this->getGradeToExecute() < executor.getGrade())
		throw AForm::GradeTooHighException();
	if (!this->getIsSigned())
		throw std::invalid_argument("Current Shrubbery Form is not signed\n");

	std::fstream art("ascii.txt", std::fstream::in);
	std::string filename = this->getTarget();
	filename.append("_shrubbery.form");
	std::fstream file(filename, std::fstream::trunc | std::fstream::out);

	if (art.fail() || file.fail())
		throw std::invalid_argument("Files have been tempered\n");
	std::string current;
	while (getline(art, current))
		file << current << std::endl;
}
