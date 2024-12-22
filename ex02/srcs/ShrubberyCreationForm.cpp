#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
{

}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string name, const int s, const int e) : AForm(name, s, e)
{

}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & other) : AForm(other)
{

}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm & other)
{
	AForm::operator=(other);
	return(*this);
}
ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor)
{
	std::cout << executor.getName() << std::endl;
}