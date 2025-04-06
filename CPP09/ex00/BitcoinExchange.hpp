/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:51:35 by fwahl             #+#    #+#             */
/*   Updated: 2024/12/02 18:25:27 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_H
#define BITCOINEXCHANGE_H

#define	GREY  "\033[38;5;246m"
#define	RESET "\033[0m"

#include <iostream>
#include <iomanip>
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

		bool							parseRates(const std::string& filename);
		void							parseInput(const std::string& filename);
		std::pair<std::string, double>	parseRatesLine(const std::string& line);
		std::pair<std::string, double>	parseInputLine(const std::string& line);
		void							checkDateFormat(const std::string& date);

		double							getRate(const std::string& date);

		class InvalidDateException : public std::exception
		{
			private:
				std::string msg;

			public:
				explicit InvalidDateException(const std::string& date);
				const char* what() const noexcept override;
		};

		class InvalidValueException : public std::exception
		{
			private:
				std::string msg;

			public:
				explicit InvalidValueException(const double value);
				const char* what() const noexcept override;
		};

		class RateNotFoundException : public std::exception
		{
			public:
				const char* what() const noexcept override;
		};

		class ValueTooLowException : public std::exception
		{
			public:
				const char* what() const noexcept override;
		};

		class ValueTooHighException : public std::exception
		{
			public:
				const char* what() const noexcept override;
		};
	private:
		std::map<std::string, double>	_btcRates;
};

#endif // BITCOINEXCHANGE_H
