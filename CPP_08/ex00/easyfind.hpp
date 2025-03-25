#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <exception>
#include <stdexcept>
#include <algorithm>

template <typename T>
int easyfind(T &container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw std::out_of_range("Value not found");
    return std::distance(container.begin(), it); 
}

#endif
