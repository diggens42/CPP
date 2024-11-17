#include "BitcoinExchange.hpp"

int main (int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: couldn't open file" << std::endl;
		std::cerr << "Enter './btc filename'" << std::endl;
		return (1);
	}
	BitcoinExchange bitcorn;
	bitcorn.parseRates("data.csv");
	bitcorn.parseInput(argv[1]);
	// bitcorn.matchData();
	return (0);
}
