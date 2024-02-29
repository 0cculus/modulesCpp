#ifndef _ROBOTOMY_HPP
# define _ROBOTOMY_HPP

# include "AForm.hpp"
# include <cstdlib>

class RobotomyRequestForm : public AForm
{
	private:
			std::string target;
	public:
		RobotomyRequestForm(std::string newTarget);
		RobotomyRequestForm(const RobotomyRequestForm& copy);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& copy);
		~RobotomyRequestForm();

		std::string getTarget() const;
		void execute(Bureaucrat const& executor) const;
};

#endif
