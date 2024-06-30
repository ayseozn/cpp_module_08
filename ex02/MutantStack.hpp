#pragma once
#include <iostream>
#include <stack>
#include <iterator>

template<typename T>
class MutantStack : public std::stack<T> {
public:
    MutantStack();
    ~MutantStack();
    MutantStack(const MutantStack& other);
    MutantStack &operator=(const MutantStack& other);

    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
   
    iterator begin();
    iterator end();

    reverse_iterator rbegin();
    reverse_iterator rend();

};

#include "MutantStack.tpp"
