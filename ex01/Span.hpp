/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 01:14:14 by fwahl             #+#    #+#             */
/*   Updated: 2024/10/04 01:14:15 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_H
#define SPAN_H

#define	GREY  "\033[38;5;246m"
#define	RESET "\033[0m"

#include <iostream>

class Span
{
	public:
		Span();
		Span(const Span &other);
		Span& operator=(const Span &other);
		~Span();

	private:

};

#endif // SPAN_H
