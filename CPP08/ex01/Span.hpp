#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>

class Span
{
    private:
        std::vector<int> _numbers;
        unsigned int _max_size;

    public:
        Span();
        Span(unsigned int n);
        Span(const Span &other);
        Span &operator=(const Span &other);
        ~Span();

        void addNumber(int num);
        void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        int shortestSpan();
        int longestSpan();

        class LengthExceededException : public std::exception{
        public:
            virtual const char *what() const throw();
    };
        class NoSpanException : public std::exception{
        public:
            virtual const char *what() const throw();
    };
};


#endif