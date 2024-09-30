#ifndef SCALARCONVERTER_H
#define SCALARCONVERTER_H

#define	GREY  "\033[38;5;246m"
#define	RESET "\033[0m"

#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <cmath>
#include <iomanip>
#include <optional>

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

};

#endif // SCALARCONVERTER_H
