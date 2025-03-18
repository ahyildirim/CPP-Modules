#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

/*
CPP'de Stack Unwinding ismi ile adlandırılan nesne yok etme sırası vardır;
Önce exception fırlatılır(throw ile),
Sonra destructor çağırılıp nesne yok edilir,
En son exception mesajı(what()) çağırılır.
Bu sebeple önce destructor mesajı ardından exception mesajı görülür.
*/

int main()
{
    std::cout << "----------NO EXCEPTION----------" << std::endl;
    try{
        Bureaucrat ahmet("Bureaucrat Ahmet", 1);
		Intern intern1;
		AForm *shrub = intern1.makeForm("ShrubberyCreationForm", "shrub");
        AForm *pres = intern1.makeForm("PresidentialPardonForm", "Ali");
		AForm *robot = intern1.makeForm("RobotomyRequestForm", "Kerem");
        std::cout << std::endl;
        ahmet.signAForm(*shrub);
        ahmet.executeForm(*shrub);
        std::cout << std::endl;
        ahmet.signAForm(*pres);
        ahmet.executeForm(*pres);
        std::cout << std::endl;
        ahmet.signAForm(*robot);
        ahmet.executeForm(*robot);
		delete shrub;
		delete pres;
		delete robot;
    }
    catch (std::exception& e){
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
    std::cout << "----------INVALID NAME----------" << std::endl;
    try{
        Bureaucrat hakan("Bureaucrat Hakan", 93);
        Intern intern2;
		AForm *form = intern2.makeForm("InvalidForm", "InvalidTarget");
		std::cout << std::endl;
		std::cout << "Forms: " << std::endl << form << std::endl;
	}
	catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}
}