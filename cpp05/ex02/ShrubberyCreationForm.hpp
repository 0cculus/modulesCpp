#ifndef _SHRUBBERY_HPP
# define _SHRUBBERY_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
			std::string target
	public:
		ShrubberyCreationForm(std::string newTarget);
		ShrubberyCreationForm(const ShrubberyCreationForm& copy);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& copy);
		~ShrubberyCreationForm();

		std::string getTarget();
		void execute(Bureaucrat& const executor) const;
};

#endif
