#ifndef FORM_H
#define FORM_H

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	public:
		static constexpr int	_minGrade = 150;
		static constexpr int	_maxGrade = 1;

		Form();
		Form(const std::string& name, int signGrade, int executeGrade);
		Form(const Form &other);
		Form& operator=(const Form &other);
		~Form();

		const std::string&	getName() const;
		bool				isSigned() const;
		int					getSignGrade() const;
		int					getExecuteGrade() const;

		void				beSigned(const Bureaucrat& bureaucrat);

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const noexcept override;
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const noexcept override;
		};

	private:
		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_executeGrade;


};

std::ostream&	operator<<(std::ostream& os, const Form& form);

#endif // FORM_H
