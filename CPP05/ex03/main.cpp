#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

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
        ShrubberyCreationForm shrub("testShrub");
        PresidentialPardonForm pres("Ali");
        RobotomyRequestForm robot("Kerem");
        std::cout << std::endl;
        std::cout << "Forms: " << std::endl << shrub << pres << robot << std::endl;
        std::cout << std::endl;
        ahmet.signAForm(shrub);
        ahmet.executeForm(shrub);
        std::cout << std::endl;
        ahmet.signAForm(pres);
        ahmet.executeForm(pres);
        std::cout << std::endl;
        ahmet.signAForm(robot);
        ahmet.executeForm(robot);
    }
    catch (std::exception& e){
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
    std::cout << "----------GRADETOOLOW----------" << std::endl;
    try{
        Bureaucrat hakan("Bureaucrat Hakan", 93);
        ShrubberyCreationForm shrub1("testShrub");
        PresidentialPardonForm pres1("Ali");
        RobotomyRequestForm robot1("Kerem");
        std::cout << std::endl;
        std::cout << "Forms: " << std::endl << shrub1 << pres1 << robot1 << std::endl;
        std::cout << std::endl;
        hakan.signAForm(shrub1);
        hakan.executeForm(shrub1);
        std::cout << std::endl;
        hakan.signAForm(pres1);
        hakan.executeForm(pres1);
        std::cout << std::endl;
        hakan.signAForm(robot1);
        hakan.executeForm(robot1);
    }
    catch (std::exception& e){
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "----------ALREADYSIGNED----------" << std::endl;
    try{
        Bureaucrat mehmet("Bureaucrat Mehmet", 1);
        ShrubberyCreationForm shrub2("testShrub");
        PresidentialPardonForm pres2("Ali");
        RobotomyRequestForm robot2("Kerem");
        std::cout << std::endl;
        std::cout << "Forms: " << std::endl << shrub2 << pres2 << robot2 << std::endl;
        std::cout << std::endl;
        mehmet.signAForm(shrub2);
        mehmet.signAForm(shrub2);
        mehmet.signAForm(pres2);
        mehmet.signAForm(pres2);
        mehmet.signAForm(robot2);
        mehmet.signAForm(robot2);
    }
    catch (std::exception& e){
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "----------NOTSIGNED----------" << std::endl;
    try{
        Bureaucrat huseyin("Bureaucrat Hüseyin", 1);
        ShrubberyCreationForm shrub3("testShrub");
        PresidentialPardonForm pres3("Ali");
        RobotomyRequestForm robot3("Kerem");
        std::cout << std::endl;
        std::cout << "Forms: " << std::endl << shrub3 << pres3 << robot3 << std::endl;
        std::cout << std::endl;
        huseyin.executeForm(shrub3);
        huseyin.executeForm(pres3);
        huseyin.executeForm(robot3);
    }
    catch (std::exception& e){
        std::cout << e.what() << std::endl;
    }
}