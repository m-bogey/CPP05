#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : _name(""), _grade(0)
{}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade)
{
    if (_grade < 1)
        throw GradeTooHighException();
    else if (_grade > 150)
        throw GradeTooLowException();
}
Bureaucrat::Bureaucrat(const Bureaucrat & other) : _name(other._name) // test sans : _name... semble affecter correctement name pour une raison obscure
{
    *this = other;
}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat & other)
{
    if (this != &other)
    {
        this->_grade = other._grade;
    }
    return (*this);
}
Bureaucrat::~Bureaucrat()
{}

const std::string& Bureaucrat::getName() const
{
    return (_name);
}
int         Bureaucrat::getGrade() const
{
    return (_grade);
}

void    Bureaucrat::incrementGrade()
{
    if (_grade <= 1)
        throw GradeTooHighException();
    _grade--;
}
void    Bureaucrat::decrementGrade()
{
    if (_grade >= 150)
        throw GradeTooLowException();
    _grade++;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat & b)
{
    os << b._name << ", bureaucrat grade " << b._grade;
    return os;
}

void    Bureaucrat::signForm(Form &form)
{
    try
    {
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << _name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }
}
