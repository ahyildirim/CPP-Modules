#include "Harl.hpp"

int main(int ac, char **av)
{
    Harl harl;

    if (ac != 2)
        harl.complain("xXx");
    harl.complain(av[1]);
    return (0);
}
