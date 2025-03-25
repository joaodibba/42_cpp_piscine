#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <list>

int generateRandomNumber(int min = 0, int max = 4)
{
    return rand() % (max - min + 1) + min;
}

template <typename T>
void testContainer(const char *containerName, T &container, int searchValue)
{
    try
    {
        std::cout << "--- " << containerName << " ---" << std::endl;
        std::cout << "Contents: ";
        for (typename T::iterator it = container.begin(); it != container.end(); it++)
            std::cout << *it << " ";
        std::cout << std::endl;
        int pos =::easyfind(container, searchValue);
        std::cout << "Found value " << searchValue << " at position " << pos << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Value " << searchValue << " not found in " << containerName << std::endl;
        std::cout << "--------------" << std::endl;
    }
}

int main()
{
    {
        std::vector<int> v;
        for (int i = 0; i < 5; i++)
            v.push_back(generateRandomNumber());

        testContainer("Vector", v, 3);
        testContainer("Vector", v, 6);
    }
    {
        std::deque<int> d;
        for (int i = 0; i < 5; i++)
            d.push_back(generateRandomNumber());

        testContainer("Deque", d, 3);
        testContainer("Deque", d, 6);
    }
    {
        std::list<int> l;
        for (int i = 0; i < 5; i++)
            l.push_back(generateRandomNumber());

        testContainer("List", l, 3);
        testContainer("List", l, 6);
    }

    return 0;
}
