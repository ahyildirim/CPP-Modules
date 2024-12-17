#include "HumanA.hpp"
#include "HumanB.hpp"

int main() {
    Weapon club("crude spiked club");  // Silahı oluşturduk
    HumanA bob("Bob", club);  // HumanA bir silah alacak
    bob.attack();  // Bob saldıracak

    Weapon sword("sharp sword");  // Yeni bir silah daha oluşturduk
    HumanB jim("Jim");  // HumanB'nin silahı yok
    jim.attack();  // Jim silahsız saldıracak

    jim.setWeapon(sword);  // Şimdi Jim'e silah veriyoruz
    jim.attack();  // Jim saldıracak

    return 0;
}