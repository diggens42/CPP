#include "BitcoinExchange.hpp"

int main (int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: couldn't open file" << std::endl;
		std::cerr << "Enter './btc filename'" << std::endl;
		return (1);
	}
	try
	{
		BitcoinExchange bitcorn;
		bitcorn.parseRates("data.csv");
		bitcorn.parseInput(argv[1]);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return (1);
	}
	return (0);
}
