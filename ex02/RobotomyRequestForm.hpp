#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm &other);
		RobotomyRequestForm& operator=(const RobotomyRequestForm &other);
		~RobotomyRequestForm();

		void		setTarget(const std::string& target);
		std::string	getTarget() const;

		void	execute(Bureaucrat const & executor) const override;
	private:
		std::string	_target;
};

#endif // ROBOTOMYREQUESTFORM_H
