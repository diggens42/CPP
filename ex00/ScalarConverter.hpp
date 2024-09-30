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

class ScalarConverter
{
	public:
		~ScalarConverter();

	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter& operator=(const ScalarConverter &other);

		static bool	isCharLiteral(const std::string& lit);
		static bool	isIntLiteral(const std::string& lit);
		static bool	isFloatLiteral(const std::string& lit);
		static bool	isDoubleLiteral(const std::string& lit);
};

#endif // SCALARCONVERTER_H
