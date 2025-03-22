#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void swap(T &first, T &second)
{
    T tmp;
    tmp = first;
    first = second;
    second = tmp;
}

template <typename T>
T min(T first, T second)
{
    return (first >= second) ? second : first;
}

template <typename T>
T max(T first, T second)
{
    return (first <= second) ? second : first;
}

#endif