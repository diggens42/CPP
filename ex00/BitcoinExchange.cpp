#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::cout << GREY << "Default constructor called" << RESET << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	std::cout << GREY << "Copy constructor called" << RESET << std::endl;
	*this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		std::cout << GREY << "Copy assignment operator called" << RESET << std::endl;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
	std::cout << GREY << "Destructor called" << RESET << std::endl;
}

std::pair<std::string, double>	BitcoinExchange::parseInputLine(const std::string& line)
{
	std::stringstream	linestream(line);
	std::string			date;
	double				value;

	std::getline(linestream, date, ',');

	linestream >> value;
	if (linestream.fail())
		throw (InvalidValueException());

	return {date, value};
}
