#include "../include/PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <climits>
#include <cstdlib>
#include <cctype>
#include <sys/time.h>
#include <iomanip>

template <typename Func, typename Container>
Container measureExecutionTimeUS(Func func, const Container &input, double &timeUs)
{
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    Container result = func(input);

    clock_gettime(CLOCK_MONOTONIC, &end);

    timeUs = ((end.tv_sec - start.tv_sec) * 1e9 + (end.tv_nsec - start.tv_nsec)) / 1000.0;

    return result;
}

bool isValidNumber(const char *str)
{
    if (str == NULL || *str == '\0')
        return false;

    if (*str == '+' || *str == '-')
        ++str;

    if (*str == '\0')
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
        std::cerr << "Usage: " << av[0] << " <integers to sort>\n";
        return 1;
    }

    std::vector<int> vec;
    std::list<int> lst;

    for (int i = 1; i < ac; ++i)
    {
        if (!isValidNumber(av[i]))
        {
            std::cerr << "Error: Invalid input '" << av[i]
                      << "'; please enter only positive integers.\n";
            return 1;
        }

        long num = std::atol(av[i]);
        if (num < 1 || num > INT_MAX)
        {
            std::cerr << "Error: Integer out of range.\n";
            return 1;
        }

        vec.push_back(static_cast<int>(num));
        lst.push_back(static_cast<int>(num));
    }

    std::cout << "Before: ";
    for (int i = 1; i < ac; ++i)
        std::cout << av[i] << " ";
    std::cout << std::endl;

    double timeVecUS = 0.0;
    std::vector<int> vecSorted =
        measureExecutionTimeUS(PmergeMe<int, std::vector>::sort, vec, timeVecUS);

    std::cout << "After: ";
    for (std::vector<int>::size_type i = 0; i < vecSorted.size(); ++i)
        std::cout << vecSorted[i] << " ";
    std::cout << std::endl;

    double timeListUS = 0.0;
    std::list<int> lstSorted =
        measureExecutionTimeUS(PmergeMe<int, std::list>::sort, lst, timeListUS);

    // std::cout << "After (list):   ";
    // for (std::list<int>::const_iterator it = lstSorted.begin(); it != lstSorted.end(); ++it)
    //     std::cout << *it << " ";
    // std::cout << std::endl;

    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " << vec.size()
              << " elements with std::vector : "
              << timeVecUS << " µs\n";

    std::cout << "Time to process a range of " << lst.size()
              << " elements with std::list   : "
              << timeListUS << " µs\n";

    return 0;
}
