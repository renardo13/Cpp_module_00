#pragma once

#include <iostream>

class Data
{
    private:
        
    
    public:int nb;
        Data();
        ~Data();
        Data(Data const& cpy);
        Data const& operator=(Data const& other);
};
