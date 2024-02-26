#ifndef _ROBOTOMY_HPP
# define _ROBOTOMY_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
			std::string target
	public:
		RobotomyRequestForm(std::string newTarget);
		RobotomyRequestForm(const RobotomyRequestForm& copy);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& copy);
		~RobotomyRequestForm();

		std::string getTarget();
		void execute(Bureaucrat& const executor) const;
};

#endif
