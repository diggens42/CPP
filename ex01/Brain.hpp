/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:40:20 by fwahl             #+#    #+#             */
/*   Updated: 2024/09/15 20:40:07 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
#define BRAIN_H
#include <string>

class Brain {
	public:
		Brain();
		Brain(const Brain &other);
		Brain& operator=(const Brain &other);
		~Brain();
		void	setIdea(std::string idea, int idx);
		std::string	getIdea(int idx) const;
	private:
		std::string _ideas[100];
};

#endif // BRAIN_H
