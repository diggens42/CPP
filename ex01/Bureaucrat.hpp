#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H
#include <iostream>
#include <string>

class Bureaucrat {
	public:
		Bureaucrat();
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat& operator=(const Bureaucrat &other);
		~Bureaucrat();

		const std::string&	getName() const;
		int					getGrade() const;
		void				setGrade(int grade);
		void				setName(std::string name);

		void		incrementGrade();
		void		decrementGrade();


		class GradeTooHighException : public std::exception
		{
			const char*	what() const noexcept;
		};

		class GradeTooLowException : public std::exception
		{
			const char*	what() const noexcept;
		};

	private:
		const std::string	_name;
		int					_grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif // BUREAUCRAT_H
