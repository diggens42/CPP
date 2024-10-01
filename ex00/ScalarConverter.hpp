#ifndef SCALARCONVERTER_H
#define SCALARCONVERTER_H

#define	GREY  "\033[38;5;246m"
#define	RESET "\033[0m"

#include <iostream>
#include <string>
#include <limits>	// std::numeric_limits
#include <cmath>	// std::isnan, std::infinity
#include <optional>	// std::optional

class ScalarConverter
{
	public:
		~ScalarConverter();
		static void	convert(const std::string& lit);

	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter& operator=(const ScalarConverter &other);

		static bool						isCharLiteral(const std::string& lit);
		static std::optional<long>		isIntOpt(const std::string& lit);
		static std::optional<float>		isFloatOpt(const std::string& lit);
		static std::optional<double>	isDoubleOpt(const std::string& lit);

		static void	printChar(char c);
		static void	printInt(long intie);
		static void	printFloat(float floatie);
		static void	printDouble(double michael_double);
};

#endif // SCALARCONVERTER_H
