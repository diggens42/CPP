#ifndef BITCOINEXCHANGE_H
#define BITCOINEXCHANGE_H

#define	GREY  "\033[38;5;246m"
#define	RESET "\033[0m"

#include <iostream>

class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange& operator=(const BitcoinExchange &other);
		~BitcoinExchange();

	private:

};

#endif // BITCOINEXCHANGE_H
