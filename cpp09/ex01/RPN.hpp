#ifndef RPN_HPP_
# define RPN_HPP_

# include <stack>
# include <string>
# include <iostream>

class RPN
{
	private:
		std::stack<int> stack;
	public:
		RPN();
		RPN(const RPN& copy);
		RPN& operator=(const RPN& copy);
		~RPN();

		void operate(char oper);
		void calculate(std::string);
};

#endif
