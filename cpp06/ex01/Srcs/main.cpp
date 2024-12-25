#include"../Includes/Serializer.hpp"
#include"../Includes/Data.hpp"

// Use reinterpret cast to convert an adress in an unsigned integer.
// it is just a way to manipulate safely a pointer
// it is like a pointer but in integer mode

int main(void)
{
    Data data;
    Serializer s;
    uintptr_t raw;
    Data *result;

    data.nb = 2;
    raw = s.serialize(&data);

    result = s.deserialize(raw);
    std::cout << "Adresse de data : " << &data << " Adresse de result :" << result << std::endl;
    std::cout << "Result.nb = " << result->nb << std::endl;
}