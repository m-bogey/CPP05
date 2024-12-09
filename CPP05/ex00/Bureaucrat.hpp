#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <stdexcept>

class Bureaucrat
{
    public:
        Bureaucrat();
        Bureaucrat(const std::string name, int grade);
        Bureaucrat(const Bureaucrat & other);
        Bureaucrat& operator=(const Bureaucrat & other);
        ~Bureaucrat();

        const std::string&    getName() const;
        int    getGrade() const;

        void    incrementGrade();
        void    decrementGrade();
        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const noexcept override
                {
                    return "Grade too high! Must be between 1 and 150.";
                }
        };
        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const noexcept override
                {
                    return "Grade too low! Must be between 1 and 150.";
                }
        };
        
        friend std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

    private:
        const std::string _name;
        int     _grade;
};

#endif