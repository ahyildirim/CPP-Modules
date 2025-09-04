#include "Span.hpp"

int main() 
{
    try{
        Span sp = Span(10005);
        std::vector<int> largeNumbers;

        sp.addNumber(7);
        sp.addNumber(41);
        sp.addNumber(33);
        sp.addNumber(25);
        sp.addNumber(13);
        
        std::cout << "Shortest span before large numbers: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span before large numbers: " << sp.longestSpan() << std::endl;
        std::cout << std::endl;

        for (int i = 0; i < 10000; ++i)
            largeNumbers.push_back(i * 2);

        sp.addNumbers(largeNumbers.begin(), largeNumbers.end());
        std::cout << "Shortest span after large numbers: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span after large numbers: " << sp.longestSpan() << std::endl;
        std::cout << std::endl;

        sp.addNumber(35);

    } catch(const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}

