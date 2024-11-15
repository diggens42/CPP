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
	checkDateFormat(date);
	linestream >> value;
	if (linestream.fail() || value < 0 || value > 1000)
		throw (InvalidValueException());
	return {date, value};
}

void	BitcoinExchange::checkDateFormat(const std::string& date)
{
	if (date.length() != 10)
		throw (InvalidDateException());

	int	i = 0;
	while (i < 10)
	{
		if ((i == 4 || i == 7))
		{
			if (date[i] != '-')
				throw (InvalidDateException());
		}
		else if (!std::isdigit(date[i]))
			throw (InvalidDateException());
		i++;
	}

	int	yyyy = std::stoi(date.substr(0, 4));
	int	mm = std::stoi(date.substr(5, 2));
	int	dd = std::stoi(date.substr(8, 2));

	if (yyyy < 2009 || yyyy > 2022 || mm < 1 || mm > 12 || dd < 1 || dd > 31)
		throw (InvalidDateException());
	if (dd == 31 && (mm == 4 || mm == 6 || mm == 9 || mm == 11))
		throw (InvalidDateException());
	if (mm == 2 && (((yyyy % 4 != 0 || (yyyy % 100 == 0 && yyyy % 400 != 0)) && dd == 29) || dd > 29))
		throw (InvalidDateException());
}
