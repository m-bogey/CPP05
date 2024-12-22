#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"

class AForm
{
    private:
        const std::string   _name;
        bool                _isSigned;
        const int           _gradeSign;
		const int			_gradeExec;

    public:
        AForm();
        AForm(const std::string name, const int s, const int e);
        AForm(const AForm & other);
        AForm& operator=(const AForm & other);
        virtual ~AForm();

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return "AForm : Grade too high!";
				}
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return "AForm : Grade too low!";
				}
		};

		const std::string getName() const;
		bool getSign() const;
		int getGradeSign() const;
		int getGradeExec() const;

		//virtual void beSigned(const Bureaucrat& b) = 0;
		void beSigned(const Bureaucrat& b);

		virtual void execute(Bureaucrat const & executor) = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm & f);

#endif