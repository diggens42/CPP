#include "RPN.hpp"

const std::string RPN::ops = "+-*/";

RPN::RPN()
{
	std::cout << GREY << "Default constructor called" << RESET << std::endl;
}

RPN::RPN(const RPN &other)
{
	std::cout << GREY << "Copy constructor called" << RESET << std::endl;
	*this = other;
}

RPN& RPN::operator=(const RPN &other)
{
	if (this != &other)
	{
		std::cout << GREY << "Copy assignment operator called" << RESET << std::endl;
	}
	return *this;
}

RPN::~RPN()
{
	std::cout << GREY << "Destructor called" << RESET << std::endl;
}

int	RPN::parseRPN(const std::string& str)
{
	std::istringstream	rpn(str);
	std::string			temp;

	while (rpn >> temp)
	{
		if (isdigit(temp[0]) || temp[0] == '-' && temp.size() > 1)
			_nums.push(std::stoi(temp));
		else if (temp.size() == 1 && ops.find(temp[0]) != std::string::npos)
		{
			if (_nums.size() < 2)
				throw (NotEnoughNumbersException());
			int b = _nums.top();
			_nums.pop();
			int a = _nums.top();
			_nums.pop();
			_nums.push(doSomeMath(a, b, temp[0]));
		}
	}
}

int	RPN::doSomeMath(int a, int b, char op)
{
	switch (op)
	{
		case '+':
			return (a + b);
		case '-':
			return (a - b);
		case '*':
			return (a * b);
		case '/':
			if (b == 0)
				throw (DivideByZeroException());
			return (a / b);
		default:
			throw (InvalidOperatorException());
	}
}

const char*	RPN::NotEnoughNumbersException::what() const noexcept
{
	return ("Error: not enough numbers on the stack");
}

const char* RPN::DivideByZeroException::what() const noexcept
{
	return ("Error: can't divide by zero");
}

const char* RPN::InvalidOperatorException::what() const noexcept
{
	return ("Error: Invalid operator");
}
