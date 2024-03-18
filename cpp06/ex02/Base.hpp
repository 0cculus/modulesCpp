#ifndef BASE_HPP_
# define BASE_HPP_

# include <iostream>

class Base
{
	public:
		virtual ~Base();
};

class A : public Base
{};

class B : public Base
{};

class C : public Base
{};

Base* generate(void);
void identify(Base* b);
void identify(Base& b);

#endif
