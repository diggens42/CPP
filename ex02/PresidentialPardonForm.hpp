#ifndef PRESIDENTIALPARDONFORM_H
#define PRESIDENTIALPARDONFORM_H

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(const PresidentialPardonForm &other);
		PresidentialPardonForm& operator=(const PresidentialPardonForm &other);
		~PresidentialPardonForm();

		void		setTarget(const std::string& target);
		std::string	getTarget() const;
		
		void	execute(Bureaucrat const & executor) const override;
	private:
		std::string	_target;
};

#endif // PRESIDENTIALPARDONFORM_H
