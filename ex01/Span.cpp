#include "Span.hpp"
#include <algorithm>
#include <cstdlib>
#include <ctime>

Span::Span() {}

Span::Span(unsigned int N): maxSize(N) {}

Span::~Span() {}

Span::Span(const Span& other) { *this = other; }

Span &Span::operator=(const Span& other)
{
    vec = other.vec;
    maxSize = other.maxSize;
    return *this;
}

void Span::addNumber(int num)
{
    if (vec.size() >= maxSize)
        throw std::out_of_range("Span: is full");
    vec.push_back(num);
}

int Span::shortestSpan()
{
    if (vec.size() <= 1)
        throw std::logic_error("Cannot find span with less than two number");
    std::vector<int> tmp = vec;
    std::sort(tmp.begin(), tmp.end());
    int span = tmp[1] - tmp[0];
    int dist = span;
    for (size_t i = 2; i < tmp.size(); ++i) 
    {
        dist = tmp[i] - tmp[i -1];
        if (dist < span)
        {
            span = dist;
        }
    }
    return span;
}

void Span::randomFill()
{
    vec.reserve(maxSize);
    iter it = vec.begin();
    srand(time(0));
    while(vec.size() < maxSize)
    {
	    *it = rand();
        addNumber(*it);
        it++;
	}  
}

void Span::print()
{
    iter it;

    for (it = vec.begin(); it != vec.end(); it++) {
        std::cout << *it << std::endl;
    }
}

int Span::longestSpan()
{
    if (vec.size() <= 1)
        throw std::logic_error("Cannot find span with less than two number");
    std::vector<int>::iterator max_it = std::max_element(vec.begin(), vec.end());
    std::vector<int>::iterator min_it = std::min_element(vec.begin(), vec.end());
    return (*max_it - *min_it);
}
