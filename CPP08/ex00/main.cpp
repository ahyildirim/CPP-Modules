#include "easyfind.hpp"
#include <vector>

int main()
{
    std::vector<int> vec;
    for (int i = 1; i <= 5; i++)
        vec.push_back(i);
    std::cout << "Elements in vector" << std::endl;
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
        std::cout << *it << ", ";
    std::cout << std::endl;
    std::cout << std::endl;

    try {
        std::cout << "Trying to find 3..." << std::endl;
        int result = easyfind(vec, 3);
        std::cout << "Found: " << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;

    try {
        std::cout << "Trying to find 25..." << std::endl;
        int result = easyfind(vec, 25);
        std::cout << "Found: " << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}