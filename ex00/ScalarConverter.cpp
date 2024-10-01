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


bool	ScalarConverter::isCharLiteral(const std::string& lit)
{
	if (lit.length() == 1 && !std::isdigit(lit[0]) && std::isprint(lit[0]))
		return (true);
	return (false);
}
std::optional<long>	ScalarConverter::isIntOpt(const std::string& lit)
{
	char*		pos;
	long		intie;
	intie = strtol(lit.c_str(), &pos, 10);
	if (*pos == '\0' && intie <= std::numeric_limits<int>::max() && intie >= std::numeric_limits<int>::min())
		return (intie);
	return (std::nullopt);
}
std::optional<float>	ScalarConverter::isFloatOpt(const std::string& lit)
{
	char*	pos;
	float	floatie;

	floatie = std::strtof(lit.c_str(), &pos);
	if (*pos == 'f' && *(pos + 1) == '\0')
		return (floatie);
	return (std::nullopt);
}
std::optional<double>	ScalarConverter::isDoubleOpt(const std::string& lit)
{
	char*	pos;
	double	michael_double;

	michael_double = strtod(lit.c_str(), &pos);
	if (*pos == '\0')
		return (michael_double);
	return (std::nullopt);
}

void	ScalarConverter::convert(const std::string& lit)
{
	if (isCharLiteral(lit) == true)
	{
		printChar(lit[0]);
		return ;
	}

	std::optional<long>		intOpt = isIntOpt(lit);
	if (intOpt.has_value())
	{
		long intie = intOpt.value();
		printInt(intie);
		return ;
	}

	std::optional<float>	floatOpt = isFloatOpt(lit);
	if (floatOpt.has_value())
	{
		float	floatie = floatOpt.value();
		printFloat(floatie);
		return ;
	}

	std::optional<double>	doubleOpt = isDoubleOpt(lit);
	if (doubleOpt.has_value())
	{
		double	michael_double = doubleOpt.value();
		printDouble(michael_double);
		return ;
	}

	std::cout << "Invalid input" << std::endl;
}

void	ScalarConverter::printChar(char c)
{
	std::cout << "Char value (literal): \'" << c << "\'" << std::endl;
	std::cout << "Int value (casted): " << static_cast<int>(c) << std::endl;
	std::cout << "Float value (casted): " << static_cast<float>(c) << "f" << std::endl;
	std::cout << "Double value (casted): " << static_cast<double>(c) << std::endl;
}

void	ScalarConverter::printInt(long intie)
{
	std::cout << "Int value (literal): " << intie << std::endl;

	if (std::isprint(intie))
		std::cout << "Char value (casted): \'" << static_cast<char>(intie) << "\'" << std::endl;
	else
		std::cout << "Char value (casted): non printable value" << std::endl;

	std::cout << "Float value (casted): " << static_cast<float>(intie) << "f" << std::endl;
	std::cout << "Double value (casted): " << static_cast<double>(intie) << std::endl;
}

void	ScalarConverter::printFloat(float floatie)
{
	std::cout << "Float value (literal): " << floatie << "f" << std::endl;

	if (std::isprint(static_cast<int>(floatie)))
		std::cout << "Char value (casted): \'" << static_cast<char>(floatie) << "\'" << std::endl;
	else
		std::cout << "Char value (casted): non printable value" << std::endl;

	if (floatie > std::numeric_limits<int>::max() || floatie < std::numeric_limits<int>::min())
		std::cout << "Int value (casted): Impossible (value out of range)" << std::endl;
	else if (floatie == std::numeric_limits<float>::infinity())
		std::cout << "Int value (casted): " << INT_MAX << std::endl;
	else if (floatie == -std::numeric_limits<float>::infinity())
		std::cout << "Int value (casted): " << INT_MIN << std::endl;
	else if (std::isnan(floatie))
		std::cout << "Int value (casted): Impossible (nan does not exist for int)" << std::endl;
	else
		std::cout << "Int value (casted): " << static_cast<int>(floatie) << std::endl;

	std::cout << "Double value (casted): " << static_cast<double>(floatie) << std::endl;
}

void	ScalarConverter::printDouble(double michael_double)
{
	std::cout << "Double value (literal): " << michael_double << std::endl;

	if (std::isprint(static_cast<int>(michael_double)))
		std::cout << "Char value (casted): \'" << static_cast<char>(michael_double) << "\'" << std::endl;
	else
		std::cout << "Char value (casted): non printable value" << std::endl;

	if (michael_double > std::numeric_limits<int>::max() || michael_double < std::numeric_limits<int>::min())
		std::cout << "Int value (casted): Impossible (value out of range)" << std::endl;
	else if (michael_double == std::numeric_limits<double>::infinity())
		std::cout << "Int value (casted): " << INT_MAX << std::endl;
	else if (michael_double == -std::numeric_limits<double>::infinity())
		std::cout << "Int value (casted): " << INT_MIN << std::endl;
	else if (std::isnan(michael_double))
		std::cout << "Int value (casted): Impossible (nan does not exist for int)" << std::endl;
	else
		std::cout << "Int value (casted): " << static_cast<int>(michael_double) << std::endl;

	std::cout << "Float value (casted): " << static_cast<float>(michael_double) << "f" << std::endl;
}
