#ifndef FORM_H
#define FORM_H

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	public:
		static constexpr int	_minGrade = 150;
		static constexpr int	_maxGrade = 1;

		AForm();
		AForm(const std::string& name, int signGrade, int executeGrade);
		AForm(const AForm &other);
		AForm& operator=(const AForm &other);
		~AForm();

		const std::string&	getName() const;
		bool				isSigned() const;
		int					getSignGrade() const;
		int					getExecuteGrade() const;

		void				beSigned(const Bureaucrat& bureaucrat);
		virtual void		execute(Bureaucrat const & executor) const = 0;

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

		class SignedExecption : public std::exception
		{
			public:
				const char* what() const noexcept override;
		};

		class NotSignedException : public std::exception
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

std::ostream&	operator<<(std::ostream& os, const AForm& form);

#endif // FORM_H
