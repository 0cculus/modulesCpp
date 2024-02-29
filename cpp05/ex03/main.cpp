#include "Intern.hpp"

int main(void){
	{
		AForm* rrf;
		try
		{
			Bureaucrat bureau("bob", 5);
			Intern someRandomIntern;
			rrf = someRandomIntern.makeForm("robotomy request", "Bender");
			bureau.signForm(*rrf);
			rrf->execute(bureau);
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
		delete rrf;
		std::cout << std::endl;
		try
		{
			Bureaucrat bureau("bobo", 5);
			Intern someRandomIntern;
			rrf = someRandomIntern.makeForm("robotomy reques", "Bender");
			bureau.signForm(*rrf);
			rrf->execute(bureau);
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
		try
		{
			Bureaucrat bureau("bobob", 46);
			Intern someRandomIntern;
			rrf = someRandomIntern.makeForm("robotomy request", "Bender");
			bureau.signForm(*rrf);
			rrf->execute(bureau);
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
		delete rrf;
		std::cout << std::endl;
		try
		{
			Bureaucrat bureau("bobobo", 150);
			Intern someRandomIntern;
			rrf = someRandomIntern.makeForm("robotomy request", "Bender");
			bureau.signForm(*rrf);
			rrf->execute(bureau);
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
		delete rrf;
	}
}
