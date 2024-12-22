#include "Form.hpp"

Form::Form() : _name(""), _isSigned(false), _gradeSign(0), _gradeExec(0)
{}

Form::Form(const std::string name, const int s, const int e) : _name(name), _gradeSign(s), _gradeExec(e)
{
    if (_gradeSign < 1 || _gradeExec < 1)
        throw GradeTooHighException();
    if (_gradeSign > 150 || _gradeExec > 150)
        throw GradeTooLowException();
}

Form::Form(const Form & other) : _name(other._name), _gradeSign(other._gradeSign), _gradeExec(other._gradeExec)
{
    *this = other;
}

Form& Form::operator=(const Form & other)
{
    if (this != &other)
        this->_isSigned = other._isSigned;
    return (*this);
}
Form::~Form()
{}

const std::string Form::getName() const
{
    return (_name);
}
bool Form::getSign() const
{
    return (_isSigned);
}
int Form::getGradeSign() const
{
    return (_gradeSign);
}
int Form::getGradeExec() const
{
    return (_gradeExec);
}

void Form::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() > _gradeSign)
        throw GradeTooLowException();
    _isSigned = true;
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
    os << "Form " << form.getName()
       << " [signed: " << (form.getSign() ? "yes" : "no")
       << ", grade to sign: " << form.getGradeSign()
       << ", grade to execute: " << form.getGradeExec() << "]";
       return (os);
}