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
 * - when do we use value_compare instead of key_compare ??
 * */

namespace ft
{
    template < class Key, class T, class Compare = std::less<Key>,
                class Allocator = std::allocator<ft::pair<const Key, T> > >
    class map
    {
        public:

            typedef Key                                         key_type;       /** the key data to be stored in the map */
            typedef T                                           mapped_type;    /** the element data type to be stored in the map */
            typedef ft::pair<const Key, mapped_type>            value_type;     /** key data pair */
            typedef std::size_t                                 size_type;
            typedef Compare                                     key_compare;    /** function object for comparision (std::less) */
            typedef Allocator                                   allocator_type;
            typedef typename allocator_type::reference          reference;
            typedef typename allocator_type::const_reference    const_reference;
            typedef typename allocator_type::pointer            pointer;
            typedef typename allocator_type::const_pointer      const_pointer;

            typedef std::ptrdiff_t                              difference_type;
            //typedef Node<value_type>                            naode_type;
            
            /** @brief member class that is used to compare keys (key value pairs)
             * by calling the stored comparator _comp of type Compare (i.e std::less)
             * */
            class value_compare
            {
                private:

                    Compare _comp; /** stored comparator (std::less) */

                    friend class map; /** the class map has acces to the private element _comp */

                public:

                    value_compare(Compare comp) : _comp(comp) {} /** assign the class function to _comp */
                    bool operator() (const value_type &x, const value_type &y) const
                    {
                        return _comp(x.first, y.first); /** true if y < x */
                    }
            };

            private:
                typedef rbTree<ft::pair<const Key, T>, value_compare>        tree_val;
            
            public: 
                /** @brief a bidirectional iterator to value_type
                 * that can read or modify any eleent stored*/
                typedef typename tree_val::iterator                         iterator;
                typedef typename tree_val::const_iterator                   const_iterator;
                typedef reverse_iterator<iterator>                 reverse_iterator; /** reverse iterator on the model of rb_iterator */
                typedef reverse_iterator<const_iterator>     const_reverse_iterator;
        
            private:

                key_compare                                     _comp;
                tree_val                                        _val;
                allocator_type                                  _alloc;
                tree_val                                        _tree;
                size_t                                          _size;  

            public:
                explicit map(const key_compare &comp = key_compare(),
                                const allocator_type &alloc = allocator_type())
                                : _comp(comp), _tree(value_compare(comp)), _alloc(alloc), _size(0) {}              

    };
}

#endif