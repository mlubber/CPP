#include "../../headers/RPN.hpp"

float	calculate(std::string argv)
{
	// std::cout << "calculate here" << std::endl;

	std::stack<float> rpn_stack;
	std::stringstream oss(argv);
	std::string token;
	while (oss >> token)
	{
		// std::cout << token << std::endl;
		if (token.length() == 1 && std::isdigit(token[0]))
			rpn_stack.push(std::stoi(token));
		else if (token == "+" || token == "-" || token == "*" || token == "/")
		{
			// std::cout << "operand found" << std::endl;
			if (rpn_stack.size() < 2)
				throw std::runtime_error("Invalid expression");
			float second = rpn_stack.top();
			rpn_stack.pop();
			float first = rpn_stack.top();
			rpn_stack.pop();
			// std::cout << first << token << second << std::endl;
			if (token == "+")
				rpn_stack.push(first + second);
			else if (token == "-")
				rpn_stack.push(first - second);
			else if (token == "*")
				rpn_stack.push(first * second);
			else
			{
				if (second == 0)
					throw std::runtime_error("Division by zero");
				rpn_stack.push(first / second);
			}
		}
		else
			throw std::runtime_error("Invalid entry");
	}
	return (rpn_stack.top());
}