#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << GREY << "Default constructor called" << RESET << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	std::cout << GREY << "Copy constructor called" << RESET << std::endl;
	*this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other)
{
	if (this != &other)
	{
		std::cout << GREY << "Copy assignment operator called" << RESET << std::endl;
	}
	return *this;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << GREY << "Destructor called" << RESET << std::endl;
}


static bool	isCharLiteral(const std::string& lit)
{
	if (lit.length() == 1 && !std::isdigit(lit[0]) && std::isprint(lit[0]))
		return (true);
	return (false);
}
static bool	isIntLiteral(const std::string& lit)
{
	char*	pos;
	strtol(lit.c_str(), &pos, 10);
	return (*pos == '\0');
}
static bool	isFloatLiteral(const std::string& lit)
{
	char*	pos;
	float	floatie;

	floatie = std::strtof(lit.c_str(), &pos);
	if (*pos == 'f' && *(pos + 1) == '\0')
		return (true);
	return (false);

	// int		start = 0;
	// bool	decimalPoint = false;
	// bool	integralPart = false;
	// bool	fractionalPart = false;

	// if (lit[0] == '+' || lit[0] == '-')
	// 	start = 1;

	// int		i = start;
	// while (i < lit.length())
	// {
	// 	if (std::isdigit(lit[i]))
	// 	{
	// 		if (!decimalPoint)
	// 			integralPart = true;
	// 		else
	// 			fractionalPart = true;
	// 	}
	// 	else if (lit[i] == '.')
	// 	{
	// 		if (decimalPoint)
	// 			return false;
	// 		decimalPoint = true;
	// 	}
	// 	else if (lit[i] == 'f')
	// 		return (i == lit.length() - 1 && decimalPoint && (integralPart || fractionalPart));
	// 	else
	// 		return false;
	// 	i++;
	// }
	// return false;
}
static bool	isDoubleLiteral(const std::string& lit)
{
	char*	pos;
	double	michael_double;

	michael_double = strtod(lit.c_str(), &pos);
	if (*pos == '\0')
		return (true);
	return (false);

	// int		start = 0;
	// bool	decimalPoint = false;
	// bool	integralPart = false;
	// bool	fractionalPart = false;

	// if (lit[0] == '+' || lit[0] == '-')
	// 	start = 1;

	// int		i = start;
	// while (i < lit.length())
	// {
	// 	if (std::isdigit(lit[i]))
	// 	{
	// 		if (!decimalPoint)
	// 			integralPart = true;
	// 		else
	// 			fractionalPart = true;
	// 	}
	// 	else if (lit[i] == '.')
	// 	{
	// 		if (decimalPoint)
	// 			return false;
	// 		decimalPoint = true;
	// 	}
	// 	else if (lit[i] == '\0')
	// 		return (decimalPoint && (integralPart || fractionalPart));
	// 	else
	// 		return false;
	// 	i++;
	// }
	// return false;
}


