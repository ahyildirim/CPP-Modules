#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{

}

Fixed::Fixed(const int value)
{
	this->setRawBits(value << _fractionalBits);
}

Fixed::Fixed(const float value)
{
	this->setRawBits(roundf(value * (1 << _fractionalBits)));
}

Fixed::Fixed(const Fixed &fixed)
{
    *this = fixed;
}

Fixed::~Fixed()
{
    
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
    _value = fixed.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const
{
    return this->_value;
}

void Fixed::setRawBits(int const raw)
{
    this->_value = raw;
}

float Fixed::toFloat(void) const
{
	return (float)_value / (1 << _fractionalBits);
}

int	Fixed::toInt(void) const
{
	return getRawBits() >> _fractionalBits;
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	return a < b ? a : b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	return a < b ? a : b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	return a > b ? a : b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	return a > b ? a : b;
}

//COMPARISON OPERATORS
bool Fixed::operator<(const Fixed &fixed) const
{
	return getRawBits() < fixed.getRawBits();
}

bool Fixed::operator>(const Fixed &fixed) const
{
	return getRawBits() > fixed.getRawBits();
}

bool Fixed::operator<=(const Fixed &fixed) const
{
	return getRawBits() <= fixed.getRawBits();
}

bool Fixed::operator>=(const Fixed &fixed) const
{
	return getRawBits() >= fixed.getRawBits();
}

bool Fixed::operator!=(const Fixed &fixed) const
{
	return getRawBits() != fixed.getRawBits();
}

bool Fixed::operator==(const Fixed &fixed) const
{
	return getRawBits() == fixed.getRawBits();
}

//ARITHMETIC OPERATORS
Fixed Fixed::operator+(const Fixed &fixed) const
{
	return Fixed(this->toFloat() + fixed.toFloat());
}

Fixed Fixed::operator-(const Fixed &fixed) const
{
	return Fixed(this->toFloat() - fixed.toFloat());
}

Fixed Fixed::operator*(const Fixed &fixed) const
{
	return Fixed(this->toFloat() * fixed.toFloat());
}

Fixed Fixed::operator/(const Fixed &fixed) const
{
	return Fixed(this->toFloat() / fixed.toFloat());
}

//POSTFIX INCREMENTATION
Fixed &Fixed::operator++()
{
	_value++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	_value++;
	return tmp;
}

Fixed &Fixed::operator--()
{
	_value--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	_value--;
	return tmp;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}
