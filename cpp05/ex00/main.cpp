#include "Bureaucrat.hpp"

int main ()
{
	{
		try
		{
			Bureaucrat b1("bubu", 62);
			std::cout << b1 << std::endl;
			b1.increment();
			std::cout << b1 << std::endl;
			Bureaucrat b2 = b1;
			std::cout << b2 << std::endl;
			std::cout << b2 << std::endl;
			b2.increment();
			b2.increment();
			b2.increment();
			std::cout << b2 << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		try
		{
			Bureaucrat bubu("Bubu", 151);
			std::cout << bubu << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		try
		{
			Bureaucrat brubru = Bureaucrat("Brubru", 0);
			std::cout << brubru << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		try
		{
			Bureaucrat bubu("Bubu", 150);
			bubu.decrement();
			std::cout << bubu << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		try
		{
			Bureaucrat brubru = Bureaucrat("Brubru", 1);
			brubru.increment();
			std::cout << brubru << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}
