#include "Span.hpp"

Span::Span() : _n(0) {}

Span::Span(unsigned int n) : _n(n) {}

Span::Span(const Span &copy) : _n(copy._n), _arr(copy._arr) {}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        _n = other._n;
        _arr = other._arr;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number)
{
    if (_arr.size() >= _n)
        throw std::out_of_range("Array is full");
    _arr.push_back(number);
}

int Span::shortestSpan()
{
    if (_arr.size() <= 1)
        throw std::out_of_range("Not enough numbers to calculate span");

    std::sort(_arr.begin(), _arr.end());

    int span = INT_MAX;
    for (size_t i = 1; i < _arr.size(); ++i)
    {
        int diff = _arr[i] - _arr[i - 1];
        if (diff < span)
            span = diff;
    }
    return span;
}

int Span::longestSpan()
{
    if (_arr.size() <= 1)
        throw std::out_of_range("Not enough numbers to calculate span");

    int min = *std::min_element(_arr.begin(), _arr.end());
    int max = *std::max_element(_arr.begin(), _arr.end());

    return max - min;
}
