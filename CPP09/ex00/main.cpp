/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:51:40 by fwahl             #+#    #+#             */
/*   Updated: 2024/11/18 19:51:41 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	bool rates_parsed = false;
	rates_parsed = bitcorn.parseRates("data.csv");
	if (rates_parsed == true)
		bitcorn.parseInput(argv[1]);
	return (0);
}
