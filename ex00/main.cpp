#include "BitcoinExchange.hpp"

int main (int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: couldn't open file" << std::endl;
		std::cerr << "Enter './btc filename'" << std::endl;
		return (1);
	}
	std::ifstream	btc_data(argv[1]);
	if (!btc_data.is_open())
	{
		std::cerr << "Error opening btc data file" << std::endl;
		return (1);
	}

	return (0);
}
