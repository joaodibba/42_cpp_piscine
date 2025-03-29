#include "../include/PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <climits>
#include <cstdlib>
#include <cctype>
#include <sys/time.h>
#include <iomanip>

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
    std::list<int>   lst;

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

    struct timespec startVec, endVec;
    clock_gettime(CLOCK_MONOTONIC, &startVec);
    std::vector<int> vecSorted = PmergeMe<int, std::vector>::sort(vec);
    clock_gettime(CLOCK_MONOTONIC, &endVec);

    long timeVecUs = (startVec.tv_nsec - endVec.tv_nsec) * 1e-9;

    std::cout << "After:  "; // with vector
    for (std::vector<int>::size_type i = 0; i < vecSorted.size(); ++i)
        std::cout << vecSorted[i] << " ";
    std::cout << std::endl;

    struct timespec startlist, endList;
    clock_gettime(CLOCK_MONOTONIC, &startlist);
    std::list<int> lstSorted = PmergeMe<int, std::list>::sort(lst);
    clock_gettime(CLOCK_MONOTONIC, &endList);
    
    long timeListUs = (startlist.tv_nsec - endList.tv_nsec) * 1e-9;


    std::cout << "After:  "; // with vector
    for (std::list<int>::const_iterator it = lstSorted.begin(); it != lstSorted.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;


    std::cout << "Time to process a range of " << vec.size()
              << " elements with std::vector : " 
              << std::fixed << std::setprecision(5) << timeVecUs << " us" << std::endl;

    std::cout << "Time to process a range of " << lst.size()
              << " elements with std::list   : " 
              << std::fixed << std::setprecision(5) << timeListUs << " us" << std::endl;

    return 0;
}
