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

void	BitcoinExchange::parseRates(const std::string& filename)
{
	std::ifstream	rates(filename);
	if (!rates.is_open())
		throw (std::runtime_error("Error: couldn't open rates file"));

	std::string	line;
	std::getline(rates, line);
	while (std::getline(rates, line))
	{
		try
		{
			std::pair<std::string, double> temp = parseRatesLine(line);
			_btcRates[temp.first] = temp.second;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;;
		}
	}

}

void	BitcoinExchange::parseInput(const std::string& filename)
{
	std::ifstream	btc_data(filename);
	if (!btc_data.is_open())
		throw (std::runtime_error("Error: couldn't open input file"));

	std::string	line;
	std::getline(btc_data, line);
	while (std::getline(btc_data, line))
	{
		try
		{
			std::pair<std::string, double> data = parseInputLine(line);
			_btcInputData[data.first] = data.second;

		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

	}
	btc_data.close();
}

std::pair<std::string, double>	BitcoinExchange::parseRatesLine(const std::string& line)
{
	std::stringstream	linestream(line);
	std::string			date;
	double				value;

	std::getline(linestream, date, ',');
	checkDateFormat(date);
	linestream >> value;
	if (linestream.fail())
		throw (InvalidValueException(value));
	return {date, value};
}

std::pair<std::string, double>	BitcoinExchange::parseInputLine(const std::string& line)
{
	std::stringstream	linestream(line);
	std::string			date;
	double				value;

	std::getline(linestream, date, ',');
	checkDateFormat(date);
	linestream >> value;
	if (linestream.fail())
		throw (InvalidValueException(value));
	if (value < 0)
		throw (ValueTooLowException());
	if (value > 1000)
		throw (ValueTooHighException());
	return {date, value};
}

void	BitcoinExchange::checkDateFormat(const std::string& date)
{
	if (date.length() != 10)
		throw (InvalidDateException(date));

	int	i = 0;
	while (i < 10)
	{
		if ((i == 4 || i == 7))
		{
			if (date[i] != '-')
				throw (InvalidDateException(date));
		}
		else if (!std::isdigit(date[i]))
			throw (InvalidDateException(date));
		i++;
	}

	int	yyyy = std::stoi(date.substr(0, 4));
	int	mm = std::stoi(date.substr(5, 2));
	int	dd = std::stoi(date.substr(8, 2));

	if (yyyy < 2009 || yyyy > 2022 || mm < 1 || mm > 12 || dd < 1 || dd > 31)
		throw (InvalidDateException(date));
	if (dd == 31 && (mm == 4 || mm == 6 || mm == 9 || mm == 11))
		throw (InvalidDateException(date));
	if (mm == 2 && (((yyyy % 4 != 0 || (yyyy % 100 == 0 && yyyy % 400 != 0)) && dd == 29) || dd > 29))
		throw (InvalidDateException(date));
}

double	BitcoinExchange::getRate(const std::string& date)
{
	auto	iter = _btcRates.find(date);

	if (iter != _btcRates.end())
		return	(iter->second);
	else
	{
		iter = _btcRates.lower_bound(date);
		if (iter == _btcRates.begin())
			throw (RateNotFoundException());
		else
		{
			--iter;
			return (iter->second);
		}
	}
}
BitcoinExchange::InvalidValueException::InvalidValueException(const double value) : msg("couldn't find rate for value: " + std::to_string(value)) {}

const char* BitcoinExchange::InvalidValueException::what() const noexcept
{
	return msg.c_str();
}

BitcoinExchange::InvalidDateException::InvalidDateException(const std::string& date) : msg("bad input => " + date) {}

const char* BitcoinExchange::InvalidDateException::what() const noexcept
{
	return msg.c_str();
}

const char*	BitcoinExchange::RateNotFoundException::what() const noexcept
{
	return ("Error: rate not found for date");
}

const char*	BitcoinExchange::ValueTooLowException::what() const noexcept
{
	return ("Error: too small a number");
}

const char*	BitcoinExchange::ValueTooHighException::what() const noexcept
{
	return ("Error: too large a number");
}
