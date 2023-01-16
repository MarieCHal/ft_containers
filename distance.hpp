#ifndef FT_DISTANCE_HPP
#define FT_DISTANCE_HPP

#include "iterator_traits.hpp"

namespace ft
{
    /** @brief return the numbers of elements between the first and last iterator 
     * returns a difference_type of iterator_traits
    */
    template< class InputIt >
    typename ft::iterator_traits<InputIt>::difference_type distance( InputIt first, InputIt last )
    {
        typename ft::iterator_traits<InputIt>::difference_type n(0);
        while (first != last)
        {
            n++;
            first++;
        }
        return (n);
    }
}

#endif