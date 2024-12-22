#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    private:

    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string name, const int s, const int e);
        ShrubberyCreationForm(const ShrubberyCreationForm & other);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm & other);
        ~ShrubberyCreationForm();

		void execute(Bureaucrat const & executor);
};

#endif