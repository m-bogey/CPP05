#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Form
{
    private:
        const std::string   _name;
        bool                _isSigned;
        const int           _gradeSign;
		const int			_gradeExec;

    public:
        Form();
        Form(const std::string name, const int s, const int e);
        Form(const Form & other);
        Form& operator=(const Form & other);
        ~Form();

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return "Form : Grade too high!";
				}
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return "Form : Grade too low!";
				}
		};

		const std::string getName() const;
		bool getSign() const;
		int getGradeSign() const;
		int getGradeExec() const;

		void beSigned(const Bureaucrat& b);

};

std::ostream& operator<<(std::ostream& os, const Form & f);

#endif