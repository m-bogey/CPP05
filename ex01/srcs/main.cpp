#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat alice("Alice", 30);
        Form formA("Formulaire : ", 21, 100);
       // std::cout << formA << std::endl;

        alice.signForm(formA);
        //std::cout << formA << std::endl;

    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}
