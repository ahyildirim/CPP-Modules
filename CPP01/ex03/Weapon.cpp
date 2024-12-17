#include "Weapon.hpp"

Weapon::Weapon(const std::string type)
{
    this->_type = type;
}

Weapon::~Weapon()
{
    
}

void Weapon::setType(std::string type)
{
    this->_type = type;
}

const std::string& Weapon::getType()
{
    return (this->_type);
}