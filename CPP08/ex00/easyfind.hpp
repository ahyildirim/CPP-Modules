#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>

class NotFoundException : public std::exception{
    public:
    virtual const char *what() const throw()
    {
        return "Element not found";
    }
};

template <typename T>
int easyfind(T& container, int n)
{
    if (std::find(container.begin(), container.end(), n) != container.end())
        return n;
    else
        throw NotFoundException();
}

#endif