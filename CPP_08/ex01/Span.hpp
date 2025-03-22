#ifndef SPAN_HPP
#define SPAN_HPP

#include <stddef.h>
#include <limits.h>
#include <vector> 
#include <stdexcept>
#include <algorithm>

class Span
{
private:
    unsigned int _n;
    std::vector<int> _arr;
    Span();

public:
    Span(unsigned int n);
    Span(const Span &copy);
    ~Span();
    Span &operator=(const Span &other);

    void addNumber(int number);
    int shortestSpan();
    int longestSpan();

    template <typename Iterator>
    void addNumbersRange(Iterator begin, Iterator end) {
        if (_arr.size() + std::distance(begin, end) > _n)
            throw std::out_of_range("Not enough space to add the range of numbers");
        _arr.insert(_arr.end(), begin, end);
    }
};

#endif