#include "AForm.hpp"

AForm::AForm() : _name(""), _isSigned(false), _gradeSign(0), _gradeExec(0)
{}

AForm::AForm(const std::string name, const int s, const int e) : _name(name), _gradeSign(s), _gradeExec(e)
{
    if (_gradeSign < 1 || _gradeExec < 1)
        throw GradeTooHighException();
    if (_gradeSign > 150 || _gradeExec > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm & other) : _name(other._name), _gradeSign(other._gradeSign), _gradeExec(other._gradeExec)
{
    *this = other;
}

AForm& AForm::operator=(const AForm & other)
{
    if (this != &other)
        this->_isSigned = other._isSigned;
    return (*this);
}
AForm::~AForm()
{}

const std::string AForm::getName() const
{
    return (_name);
}

bool AForm::getSign() const
{
    return (_isSigned);
}

int AForm::getGradeSign() const
{
    return (_gradeSign);
}

int AForm::getGradeExec() const
{
    return (_gradeExec);
}

void AForm::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() > _gradeSign)
        throw GradeTooLowException();
    _isSigned = true;
}

std::ostream& operator<<(std::ostream& os, const AForm & aform)
{
    os << "AForm " << aform.getName()
    << " [signed: " << (aform.getSign() ? "yes" : "no")
    << ", grade to sign: " << aform.getGradeSign()
    << ", grade to execute: " << aform.getGradeExec() << "]";
   return (os);
}