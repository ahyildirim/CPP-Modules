#include "Span.hpp"

Span::Span() : _max_size(0) {}

Span::Span(unsigned int n) : _max_size(n) {}

Span::Span(const Span &other) : _numbers(other._numbers), _max_size(other._max_size) {}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        _numbers = other._numbers;
        _max_size = other._max_size;
    }
    return *this;
}

Span::~Span() {}

const char* Span::LengthExceededException::what() const throw()
{
    return "Length exceeded";
}

const char* Span::NoSpanException::what() const throw()
{
    return "No span found";
}

void Span::addNumber(int num)
{
    if (_numbers.size() >= _max_size)
        throw LengthExceededException();
    _numbers.push_back(num);
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if (std::distance(begin, end) + _numbers.size() > _max_size)
        throw LengthExceededException();
    _numbers.insert(_numbers.end(), begin, end);
}

int Span::longestSpan()
{
    if (_numbers.size() < 2)
        throw NoSpanException();

    int min = *std::min_element(_numbers.begin(), _numbers.end());
    int max = *std::max_element(_numbers.begin(), _numbers.end());
    return max - min;
}

int Span::shortestSpan()
{
    if (_numbers.size() < 2)
        throw NoSpanException();

    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());

    int min_span = std::numeric_limits<int>::max();
    for (size_t i = 1; i < sorted.size(); ++i)
    {
        int span = sorted[i] - sorted[i - 1];
        if (span < min_span)
            min_span = span;
    }
    return min_span;
}