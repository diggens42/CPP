#ifndef BITCOINEXCHANGE_H
#define BITCOINEXCHANGE_H

#define	GREY  "\033[38;5;246m"
#define	RESET "\033[0m"

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <exception>


class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange& operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		std::pair<std::string, double>	parseInputLine(const std::string& line);


		class InvalidDateException : public std::exception
		{
			public:
				const char* what() const noexcept override;
		};

		class InvalidValueException : public std::exception
		{
			public:
				const char* what() const noexcept override;
		}

	private:
		std::map<std::string, double>	_btcData;

};

#endif // BITCOINEXCHANGE_H
