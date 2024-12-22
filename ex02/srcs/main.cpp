#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    try {
        Bureaucrat alice("Alice", 30);
        ShrubberyCreationForm AFormA("AFormulaire : ", 21, 100);
        AFormA.execute(alice);
       // std::cout << AFormA << std::endl;

        alice.signAForm(AFormA);
        //std::cout << AFormA << std::endl;

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}
