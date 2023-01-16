#ifndef RB_TREE
#define RB_TREE

#include <functional>
#include <cstddef>
#include "iterator_traits.hpp"

/** SRCS:   Introduction to algorithms 3rd Edition
 *          https://www.programiz.com/dsa/red-black-tree
 * 
 * /** @brief a red balck three is a self balacing binary search three
 * it has the following properties:
 * - every node is coloured
 * - the root is black
 * - every leaf is black
 * - if a red node has a child it will always be black
 * - from a given node to any of it descendent the path has
 * the same black depth (no of black leafs) 
 * 
 * a binary search tree is a data structure that allows 
 * operations to be done in O(log n) worst-case time. 
 * 
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
 * TODO:
 *      alogrithms:
 *      - left rotate
 *      - 
 * 
 * */

/** @brief a red-black node contains nodes that store:
 *  - its color (black = false, red = true)
 *  - its key (in this case the map pair object to be stored)
 *  - a pointer to its left child
 *  - a pointer to its rigth child
 *  - a pointer to its parent node (except fot root node)
 * */



namespace ft
{
    enum color { black = false, red = true}; /** false reprsent color black and true red */

    /** @brief struct node
     * contains infos: 
     *  node type (T), 
     *  pointer to the key/data pair, to the left and right
     *  its color (for self balancing)
     * 
     * */
    template <class T>
    struct Node
    {
        typedef T                       value_type; /** the value type of the stored data */
        typedef Node<value_type>        node;       /** a node of type T*/
        typedef Node<value_type>*       ptr_node;      /** ptr of type node<T> */

        /** elements contained in a node */
        public:
        ptr_node                        r_child; /** pointer to right node child */
        ptr_node                        l_child; /** pointer to left node child */
        ptr_node                        parent;  /** pointer to parent node */
        T                               data;    /** data stored(map element) */



    };



    template<class T>
    class rbTree
    {
        /** @brief biderectional iterator needed to iter through the map */
        template < class T>
        class rbIterator
        {
            public:
                typedef struct bidirectional_iterator_tag   iterator_category;
                typedef ptrdiff_t                           difference_type;
                typedef T                                   value_type;
                typedef T*                                  pointer;
                typedef T&                                  reference;

        };

        /** @brief private member of the class rbtree */
        private:

        public:
        /** @brief inserting a new node:
         * a new node is always inserted and colored red
         * if it violates the red-black tree properties than the following operations are executed:
         * 1. Recolor
         * 2. Rotation
         * */
        private:
        /** @brief right rotation **/

        /** @brief left rotation **/

        private:
        /** @brief alorithm to maintain red-black tree properties after inserting a new node **/

    };

};

#endif