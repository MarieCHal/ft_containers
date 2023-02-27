#ifndef FT_ALGORITHM_HPP
#define FT_ALGORITHM_HPP

#include "distance.hpp"

namespace ft
{

    /** @brief checks if the range [fist1, last1] is equal to the range [first2, 
     * first2 +(last1 -first1)]
     * using the operator== */
    template< class InputIt1, class InputIt2 >
    bool equal( InputIt1 first1, InputIt1 last1, InputIt2 first2 )
    {
        while (first1 != last1)
        {
            if (!(*first1 == *first2))
                return false;
            first1++;
            first2++;
        }
        return true;
    }

    /** @brief compares the value in the range [first1, last1] 
     * 
    template< class InputIt1, class InputIt2, class BinaryPredicate >
    bool equal( InputIt1 first1, InputIt1 last1, InputIt2 first2, BinaryPredicate p )
    {

    }*/

    /** @brief: Assigns the given value to all the elements in the 
     * given range using iterators */
    template <class ForwardIterator, class T>
    void fill(ForwardIterator first, ForwardIterator last, const T& val)
    {
        while (first != last)
        {
            *first = val;
            ++first;
        }
    }

    /** @brief: copies the element from the range defined by first and last
     * with last element being at posistion pos, copies backward from that pos.
     * */
    template<typename iterator, typename InputIterator>
    iterator copy_backward(InputIterator first, InputIterator last, iterator pos)
    {
        first--;
        last--;
        size_t n = ft::distance(first, last);
        pos = pos + n - 1;
        while (last != first)
        {
            *pos = *last;
            last--;
            pos--;
        }
        return pos + n;
    }

    /** @brief copies the content defined by [first, last] to another range
     * beggining at d_first */
    template< class InputIt, class OutputIt >
    OutputIt copy( InputIt first, InputIt last, OutputIt d_first )
    {
        while (first != last)
        {
            *d_first = *first;
            first++;
            d_first++;
        }
        return d_first;
    }

    /** @brief check is the range defined by first1 and last1 are lexicographyically
     * less than the seccond range using the operator< */
    template <class InputIt1, class InputIt2>
    bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2)
    {
        while (first1 != last1)
        {
            if (first2 == last2 || *first2 < *first1) return false;
            else if (*first1 < *first2) return true;
            ++first1;
            ++first2;
        }
        return (first2 != last2);
    }


    /** @brief calls the = operator of template class T */
    template <class T>
    void swap (T &lhs, T &rhs)
    {
        T tmp(lhs);
        lhs = rhs;
        rhs = tmp;
    }
}

#endif