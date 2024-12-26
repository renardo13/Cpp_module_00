#pragma once

#include <iostream>

class Data
{
    public:
        Data();
        ~Data();
        Data(Data const& cpy);
        Data const& operator=(Data const& other);
        
        int nb;
};
