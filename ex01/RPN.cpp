#include "RPN.hpp"

const std::string RPN::ops = "+-*/";

RPN::RPN()
{
	// std::cout << GREY << "Default constructor called" << RESET << std::endl;
}

RPN::RPN(const RPN &other)
{
	// std::cout << GREY << "Copy constructor called" << RESET << std::endl;
	_nums = other._nums;
}

RPN& RPN::operator=(const RPN &other)
{
	// std::cout << GREY << "Copy assignment operator called" << RESET << std::endl;
	if (this != &other)
	{
		_nums = other._nums;
	}
	return *this;
}

RPN::~RPN()
{
	// std::cout << GREY << "Destructor called" << RESET << std::endl;
}

void	RPN::evaluateRPN(const std::string& str)
{
	std::istringstream	rpn(str);
	std::string			temp;

	while (rpn >> temp)
	{
		if (isdigit(temp[0]) || (temp[0] == '-' && temp.size() > 1))
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
		else
			throw (InvalidCharacterException());
	}
	if (_nums.size() != 1)
		throw (InvalidInputException());
	std::cout << _nums.top() << std::endl;
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

const char* RPN::InvalidCharacterException::what() const noexcept
{
	return ("Error: Invalid character");
}

const char* RPN::InvalidInputException::what() const noexcept
{
	return ("Error: Invalid input, more than 1 number remaining on stack after evaluation");
}
