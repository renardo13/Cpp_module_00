#pragma once

#include <iostream>
#include <stdint.h>
#include "Data.hpp"

class Serializer
{

    public:
        Serializer();
        ~Serializer();
        Serializer(Serializer const& cpy);
        Serializer const& operator=(Serializer const& other);

        static uintptr_t serialize(Data *ptr);
        static Data* deserialize(uintptr_t raw);

};