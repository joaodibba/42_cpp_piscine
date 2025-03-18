#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <stdint.h>

struct Data {
    int number;
    float value;
};

class Serializer
{
private:
    Serializer();
    ~Serializer();
    Serializer(const Serializer &other);
    Serializer &operator=(const Serializer &copy);

public:
    static uintptr_t serialize(Data *ptr)
    {
        return reinterpret_cast<uintptr_t>(ptr);
    }

    static Data *deserialize(uintptr_t raw)
    {
        return reinterpret_cast<Data *>(raw);
    }
};

#endif