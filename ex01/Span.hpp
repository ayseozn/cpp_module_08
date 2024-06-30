#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iostream>

typedef std::vector<int>::iterator iter;

class Span {
    public:
        Span(unsigned int N);
        ~Span();
        Span(const Span& other);
        Span &operator=(const Span& other);
        void addNumber(int num);
        int shortestSpan();
        int longestSpan();
        void print();
        void randomFill();
    private:
        Span();
        std::vector<int> vec;
        unsigned int maxSize;
};

#endif