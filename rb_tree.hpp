#ifndef RB_TREE
#define RB_TREE

#include <functional>
#include <cstddef>
#include "iterator_traits.hpp"

/** SRCS: Introduction to algorithms 3rd Edition
 * 
 * @brief a binary search tree is a data structure that allows 
 * operations to be done in O(log n) worst-case time. 
 * Operations:
 *  - SEARCH --> recursive
 *  - MINIMUM
 *  - MAXIMUM
 *  - PREDECESSOR
 *  - INSERT
 *  - DELETE
 * 
 * A variant of binary search tree is the red black tree that arrange
 * data in such a way that it guarantees this execution time 
 * the time taken is proportional to the height of the tree  
 * the red-black tree operations will be used only for the functions:
 * - 
 * - 
 * 
 * 
 * */

namespace ft
{
    // black = false ; red = true
    /** @brief struct node
     * contains infos: node type (T), 
     * pointer to the key/data pair, to the left and right
     * its color (for self balancing)
     * */



    /** @brief biderectional iterator needed to iter through the map */
    template < class T>
    class rbIterator
    {
        public:

            /** @brief iterator requirements */
            typedef struct bidirectional_iterator_tag   iterator_category;
            //maybe not necessary
            typedef ptrdiff_t                           difference_type;
            typedef T                                   value_type;
            typedef T*                                  pointer;
            typedef T&                                  reference;

    };

};

#endif