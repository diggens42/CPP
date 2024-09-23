#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

class Bureaucrat {
	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat& operator=(const Bureaucrat &other);
		~Bureaucrat();

		std::string getName();
		int			getGrade();
		void		setGrade(int grade);
		void		setName(std::string name);

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

#endif // BUREAUCRAT_H
