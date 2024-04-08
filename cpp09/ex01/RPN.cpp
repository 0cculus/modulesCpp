#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const RPN& copy)
{
	(*this) = copy;
}

RPN& RPN::operator=(const RPN& copy)
{
	this->stack = copy.stack;
	return (*this);
}

RPN::~RPN()
{
}

void RPN::operate(char oper)
{
	int currentNb[2];
	currentNb[0] = this->stack.top();
	this->stack.pop();
	currentNb[1] = this->stack.top();
	this->stack.pop();
	switch (oper)
	{
		case '+':
			this->stack.push(currentNb[1] + currentNb[0]);
			break;
		case '-':
			this->stack.push(currentNb[1] - currentNb[0]);
			break;
		case '/':
			if (currentNb[0] == 0)
				throw std::invalid_argument("Error: cannot divide by zero");
			else
				this->stack.push(currentNb[1] / currentNb[0]);
			break;
		case '*':
			this->stack.push(currentNb[1] * currentNb[0]);
			break;
	}
}

void RPN::calculate(std::string src)
{
	for (size_t i = 0; i < src.length(); i++)
	{
		if (std::isdigit(src[i]))
			this->stack.push(static_cast<int>(src[i] - '0'));
		else if (src[i] == '-' || src[i] == '+' || src[i] == '/' || src[i] == '*')
			operate(src[i]);
	}
	std::cout << this->stack.top() << std::endl;
}
