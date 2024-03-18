#include "Base.hpp"

Base::~Base()
{
}

Base* generate(void)
{
	std::srand(std::time(nullptr));
	switch (std::rand() % 3)
	{
		case 2:
			return (new A);
		case 1:
			return (new B);
		case 0:
			return (new C);
	}
	return (NULL);
}

void identify(Base* b)
{
	if (dynamic_cast<A*>(b))
		std::cout << "A" << std::endl;
	if (dynamic_cast<B*>(b))
		std::cout << "B" << std::endl;
	if (dynamic_cast<C*>(b))
		std::cout << "C" << std::endl;
}

void identify(Base& b)
{
	try
	{	
		(void)(dynamic_cast<A&>(b));
		std::cout << "A" << std::endl;
		return ;
	}
	catch (std::exception& e) {}
	try
	{
		(void)(dynamic_cast<B&>(b));
		std::cout << "B" << std::endl;
		return ;
	}
	catch (std::exception& e) {}
	try
	{
		(void)(dynamic_cast<C&>(b));
		std::cout << "C" << std::endl;
		return ;
	}
	catch (std::exception& e) {}
}
