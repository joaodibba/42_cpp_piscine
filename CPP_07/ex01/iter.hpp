#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

template <typename T, typename Func>
void iter(T *array, size_t len, Func f)
{
    for (size_t i = 0; i < len; ++i)
        f(array[i]);
}

#endif
