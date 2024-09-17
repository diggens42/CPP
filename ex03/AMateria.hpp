/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:39:49 by fwahl             #+#    #+#             */
/*   Updated: 2024/09/17 17:47:54 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_H
#define AMATERIA_H

#include <string>
#include <iostream>

class ICharacter;

class AMateria {
	public:
		AMateria();
		AMateria(const AMateria &other);
		AMateria(std::string const & type);
		virtual ~AMateria();
		AMateria& operator=(const AMateria &other);

		std::string const & getType() const;
		void	setType(std::string const & type);

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
	protected:
		std::string	_type;
};

#endif // AMATERIA_H
