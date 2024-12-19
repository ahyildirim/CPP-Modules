#include "Harl.hpp"

void Harl::debug (void) 
{
    std::cout << "[DEBUG]" << std::endl << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info (void) 
{
    std::cout << "[INFO]" << std::endl << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning (void) 
{
    std::cout << "[WARNING]" << std::endl << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error (void) 
{
    std::cout << "[ERROR]" << std::endl << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
    void (Harl::*ptrToMember[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int i = 0;
    for (; i < 4; i++)
    {
        if (levels[i] == level)
            break;
    }

    switch(i)
    {
        case (0):
            (this->*ptrToMember[0])();
            __attribute__ ((fallthrough));
        case (1):
            (this->*ptrToMember[1])();
            __attribute__ ((fallthrough));
        case (2):
            (this->*ptrToMember[2])();
            __attribute__ ((fallthrough));
        case (3):
            (this->*ptrToMember[3])();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
            break;
    }
}
