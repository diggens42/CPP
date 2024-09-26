/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:40:27 by fwahl             #+#    #+#             */
/*   Updated: 2024/09/26 16:40:50 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H
#define	GREY  "\033[38;5;246m"
#define	RESET "\033[0m"

#include <iostream>
#include <string>

class Bureaucrat {
	public:
		static constexpr int	_minGrade = 150;
		static constexpr int	_maxGrade = 1;

		Bureaucrat();
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat& operator=(const Bureaucrat &other);
		~Bureaucrat();

		const std::string&	getName() const;
		int					getGrade() const;
		void				setGrade(int grade);

		void		incrementGrade();
		void		decrementGrade();


		class GradeTooHighException : public std::exception
		{
			const char*	what() const noexcept override;
		};

		class GradeTooLowException : public std::exception
		{
			const char*	what() const noexcept override;
		};

	private:
		const std::string		_name;
		int						_grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif // BUREAUCRAT_H
