#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

#define BIG_SPAN_SIZE 1000000

void testSubject()
{
    std::cout << "-------- Test from Subject ---------" << std::endl;
    try
    {
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

void testExtra()
{
    std::cout << "------------ Test extra ------------" << std::endl;
    try
    {
        Span span(10);

        span.addNumber(5);
        span.addNumber(10);
        span.addNumber(15);
        span.addNumber(20);
        span.addNumber(25);
        span.addNumber(30);
        span.addNumber(35);
        span.addNumber(40);
        span.addNumber(45);
        span.addNumber(50);

        span.addNumber(55); // Should throw an exception
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

void testOneElement()
{
    std::cout << "-------- Test One Element 1 --------" << std::endl;
    try
    {
        Span span(1);

        std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "-------- Test One Element 2 --------" << std::endl;
    try
    {
        Span span(1);

        std::cout << "Longest span: " << span.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

void testBigSpanSize()
{
    std::cout << "-------- Test Big Span Size --------" << std::endl;
    try
    {
        Span span(BIG_SPAN_SIZE);

        std::srand(std::time(0));
        for (unsigned int i = 0; i < BIG_SPAN_SIZE; ++i)
        {
            span.addNumber(std::rand() % BIG_SPAN_SIZE);
        }

        std::cout << "Shortest span in large span: " << span.shortestSpan() << std::endl;
        std::cout << "Longest span in large span: " << span.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

void testRange()
{
    std::cout << "------------ Test Range ------------" << std::endl;
    try
    {
        Span span(10);
        std::vector<int> numbers;

        numbers.push_back(10);
        numbers.push_back(20);
        numbers.push_back(30);
        numbers.push_back(40);
        numbers.push_back(50);
        numbers.push_back(60);
        numbers.push_back(70);
        numbers.push_back(80);
        numbers.push_back(90);
        numbers.push_back(100);

        span.addNumbersRange(numbers.begin(), numbers.end());

        std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
        std::cout << "Longest span: " << span.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

int main()
{
    // Should not throw any exception
    testSubject();
    testRange();
    testBigSpanSize();
    // Should throw an exception
    testExtra();
    testOneElement();

    return 0;
}
