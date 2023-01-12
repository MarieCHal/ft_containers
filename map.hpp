#ifndef FT_MAP_HPP
#define FT_MAP_HPP



//============ INCLUDES ===============
#include <memory>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstddef>
#include <stdexcept>
#include "algorithm.hpp"
#include "enable_if.hpp"
#include "reverse_iterator.hpp"
#include "distance.hpp"
#include "pair.hpp"
#include "rb_tree.hpp"

/** SRCS: 
 * https://learn.microsoft.com/en-us/cpp/standard-library/map-class?view=msvc-170#value_comp
 * https://en.cppreference.com/w/cpp/container/map
 * */

/** @brief map<key_type, value_type>map_name
 * the elements are stocked by pairs a key and the data, 
 * the keys are constants and uniques and enable direct access
 * to the stocked data
 * */

/** TODO:
 * - class key
 * - class Compare
 * - ft::less<key>??
 * - class pair
 * - class member value_compare
 * - check what is part of the class compare
 * - look up the headers
 * */

namespace ft
{
    template < class Key, class T, class Compare = std::less<Key>,
                class Allocator = std::allocator<ft::pair<const Key, T> > >
    class map
    {
        public:

            /** the key data to be stored in the map */
            typedef Key                                         key_type;
            /** the element data type to be stored in the map */
            typedef T                                           mapped_type;
            /** pair containing the key and the data */
            typedef ft::pair<const Key, mapped_type>            value_type;;
            typedef std::size_t                                 size_type;
            /** type providing a function object that can compare two
             * elements values as sort keys to determine theire relative order
             * in the map. (default value : less<key>) */
            typedef Compare                                     key_compare;
            /** a class that is used for all memory operation */
            typedef Allocator                                   allocator_type;
            typedef typename allocator_type::reference          reference;
            typedef typename allocator_type::const_reference    const_reference;
            typedef typename allocator_type::pointer            pointer;
            typedef typename allocator_type::const_pointer      const_pointer;
            // biderectional iterator (rb three?, simple bidirectional iter)
            // is used as the type of iterator for rev it
            /** @brief a bidirectional iterator to value_type
             * that can read or modify any eleent stored*/

            typedef std::ptrdiff_t                              difference_type;
            //typedef Node<value_type>                            naode_type;

            /** @brief member class that is used to compare keys 
             * gets as param of constructor the function (std::les)
             * stocks it in the object _comp of the class 
             * has an operator oveload that returns the return value of _comp
            */
            class value_compare
            {
                private:

                    Compare _comp;

                    //friend class map?;
                    //no destructor?

                public:

                    //typedef bool result_type;

                    value_compare(Compare comp) : _comp(comp) {}
                    bool operator() (const value_type &x, const value_type &y) const
                    {
                        return _comp(x.first, y.first);
                    }

            };
        
            private:

                key_compare                                     _comp;
                // tree_val                                     _val;
                allocator_type                                  _alloc;
                size_t                                          _size;                  

    };
}

#endif