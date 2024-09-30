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
		//add print
	}

	std::optional<long>		intOpt = isIntOpt(lit);
	if (intOpt.has_value())
	{
		long intie = intOpt.value();
		//add print
	}

	std::optional<float>	floatOpt = isFloatOpt(lit);
	if (floatOpt.has_value())
	{
		float	floatie = floatOpt.value();
		//add print
	}

	std::optional<double>	doubleOpt = isDoubleOpt(lit);
	if (doubleOpt.has_value())
	{
		double	michael_double = doubleOpt.value();
		//add print
	}

	std::cout << "Invalid input" << std::endl;
}
