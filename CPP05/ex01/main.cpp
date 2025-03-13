#include "Bureaucrat.hpp"
#include "Form.hpp"

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
        Bureaucrat ahmet("Bureaucrat Ahmet", 42);
        std::cout << ahmet << std::endl;
        Form form1("Form A", 43, 43);
        std::cout << form1 << std::endl;
        ahmet.signForm(form1);
    }
    catch (std::exception& e){
        std::cout << e.what() << std::endl;
    }

    std::cout << "----------GRADETOOHIGH(CONSTRUCTOR)----------" << std::endl;
    try{
        Bureaucrat hakan("Bureaucrat Hakan", 15);
        std::cout << hakan << std::endl;
        Form form2("Form B", 0, 0);
        std::cout << form2 << std::endl;
    }
    catch (std::exception& e){
        std::cout << e.what() << std::endl;
    }

    std::cout << "----------GRADETOOLOW(CONSTRUCTOR)----------" << std::endl;
    try{
        Bureaucrat yusuf("Bureaucrat Yusuf", 15);
        std::cout << yusuf << std::endl;
        Form form3("Form C", 151, 151);
        std::cout << form3 << std::endl;
    }
    catch (std::exception& e){
        std::cout << e.what() << std::endl;
    }

    std::cout << "----------GRADETOOLOW----------" << std::endl;
    try{
        Bureaucrat huseyin("Bureaucrat Hüseyin", 27);
        std::cout << huseyin << std::endl;
        Form form4("Form D", 26, 26);
        std::cout << form4 << std::endl;
        huseyin.signForm(form4);
    }
    catch (std::exception& e){
        std::cout << e.what() << std::endl;
    }
}