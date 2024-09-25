#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm &other);
		~ShrubberyCreationForm();

		void		setTarget(const std::string& target);
		std::string	getTarget() const;

		void		execute(Bureaucrat const & executor) const override;

	private:
		std::string	_target;
};

#endif // SHRUBBERYCREATIONFORM_H
