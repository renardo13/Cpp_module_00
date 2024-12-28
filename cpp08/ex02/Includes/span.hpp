#pragma once

#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>

class Span
{
    private:
        std::vector<int> _tab;
        unsigned int _N;

    public:
        Span();
        ~Span();
        Span(Span const &cpy);
        Span const& operator=(Span const &other);

        Span(unsigned int N);
        void addNumber(int nb);

        int shortestSpan() const;
        int longestSpan() const;
        void fillUpWithRange(unsigned int start, unsigned int end, int value);

        // To access elements
        int& operator[](unsigned int i);
        
        // Exception
        class VectorIsFull : public std::exception
        {
            virtual const char*what() const throw()
            {
                return("Vector is empty or full, it is impossible to add elements.");
            }
        };
        class ImpossibleComparison : public std::exception
        {
            virtual const char*what() const throw()
            {
                return("Vector is empty or has one value.");
            }
        };
};
