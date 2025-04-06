/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:28:03 by fwahl             #+#    #+#             */
/*   Updated: 2024/09/26 16:28:42 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include "AForm.hpp"

class AForm;

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

		void				incrementGrade();
		void				decrementGrade();

		void				signForm(AForm& form);
		void				executeForm(AForm const & form);

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
