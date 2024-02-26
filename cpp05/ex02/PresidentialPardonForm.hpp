#ifndef _PRESIDENTIAL_HPP
# define _PRESIDENTIAL_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
			std::string target
	public:
		PresidentialPardonForm(std::string newTarget);
		PresidentialPardonForm(const PresidentialPardonForm& copy);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& copy);
		~PresidentialPardonForm();

		std::string getTarget();
		void execute(Bureaucrat& const executor) const;
};

#endif
