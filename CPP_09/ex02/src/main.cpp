#include "../include/PmergeMe.hpp"

#include <iostream>
#include <vector>
#include <cstdlib>
#include <climits>
#include <cstring>
#include <cctype>

bool isValidNumber(const char *str)
{
    if (!str || !*str)
        return false;

    if (*str == '+' || *str == '-')
        ++str;

    if (!*str)
        return false;

    while (*str)
    {
        if (!std::isdigit(*str))
            return false;
        ++str;
    }

    return true;
}

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cerr << "Usage: ./PmergeMe <integers to sort>" << std::endl;
        return 1;
    }

    std::vector<int> input;

    for (int i = 1; i < ac; ++i)
    {
        if (!isValidNumber(av[i]))
        {
            std::cerr << "Error: Invalid input. Please enter valid integers." << std::endl;
            return 1;
        }

        long num = std::atol(av[i]);
        if (num < INT_MIN || num > INT_MAX)
        {
            std::cerr << "Error: Integer out of range." << std::endl;
            return 1;
        }

        input.push_back(static_cast<int>(num));
    }

    std::vector<int> sorted = PmergeMe::sort(input);

    for (std::size_t i = 0; i < sorted.size(); ++i)
    {
        std::cout << sorted[i];
        if (i + 1 < sorted.size())
            std::cout << " ";
    }

    std::cout << std::endl;

    return 0;
}
