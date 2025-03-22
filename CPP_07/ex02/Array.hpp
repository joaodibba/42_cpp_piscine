#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept> // for std::exception
#include <cstddef>   // for size_t
#include <time.h>
#include <stdlib.h>


template <typename T>
class Array {
private:
    T* _data;
    unsigned int _size;

public:
    Array();

    Array(unsigned int n);

    Array(const Array& other);

    Array& operator=(const Array& other);

    ~Array();

    T& operator[](unsigned int index);
    const T& operator[](unsigned int index) const;

    unsigned int size() const;
};

#include "Array.tpp"
#endif
