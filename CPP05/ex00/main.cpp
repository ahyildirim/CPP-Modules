#include "Bureaucrat.hpp"

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
        ahmet.decraseGrade();
        std::cout << ahmet << std::endl;
        ahmet.increaseGrade();
        std::cout << ahmet << std::endl;
    }
    catch (std::exception& e){
        std::cerr << e.what() << std::endl;
    }

    std::cout << "----------GRADETOOHIGH(CONSTRUCTOR)----------" << std::endl;
    try{
        Bureaucrat hakan("Bureaucrat Hakan", 0);
        std::cout << hakan << std::endl;
    }
    catch (std::exception& e){
        std::cerr << e.what() << std::endl;
    }

    std::cout << "----------GRADETOOHIGH----------" << std::endl;
    try{
        Bureaucrat mehmet("Bureaucrat Mehmet", 1);
        std::cout << mehmet << std::endl;
        mehmet.increaseGrade();
    }
    catch (std::exception& e){
        std::cerr << e.what() << std::endl;
    }

    std::cout << "----------GRADETOOLOW(CONSTRUCTOR)----------" << std::endl;
    try{
        Bureaucrat yusuf("Bureaucrat Yusuf", 151);
        std::cout << yusuf << std::endl;
    }
    catch (std::exception& e){
        std::cerr << e.what() << std::endl;
    }

    std::cout << "----------GRADETOOLOW----------" << std::endl;
    try{
        Bureaucrat huseyin("Bureaucrat Hüseyin", 150);
        std::cout << huseyin << std::endl;
        huseyin.decraseGrade();
    }
    catch (std::exception& e){
        std::cerr << e.what() << std::endl;
    }
}