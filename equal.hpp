#ifndef EQUAL_HPP
#define EQUAL_HPP

#include "vector.hpp"

namespace ft
{

    template <class ForwardIterator, class T>
    void fill(ForwardIterator first, ForwardIterator last, const T& val)
    {
        while (first != last)
        {
            *first = val;
            ++first;
        }
    }

    template<typename iterator, typename InputIterator>
    iterator copy_backward(InputIterator first, InputIterator last, iterator pos)
    {
        first--;
        last--;
        size_t n = std::distance(first, last);
        pos = pos + n - 1;
        while (last != first)
        {
            *pos = *last;
            last--;
            pos--;
        }
        return pos +n;
    }

    
}

#endif