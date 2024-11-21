/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:51:00 by fwahl             #+#    #+#             */
/*   Updated: 2024/11/21 03:19:45 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <PmergeMe.hpp>

int main(int argc, char **argv)
{
	PmergeMe mergeinsert(argc, argv);
	mergeinsert.sortVec();
	mergeinsert.sortDeq();
	mergeinsert.printResult();
	return (0);
}
