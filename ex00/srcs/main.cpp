#include <stdexcept>
#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat b1("toto", 10);
        std::cout << b1 << std::endl;
        b1.incrementGrade();
        std::cout << b1 << std::endl;
        b1.decrementGrade();
        std::cout << b1 << std::endl;
        b1.decrementGrade();
        std::cout << b1 << std::endl;

    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}
