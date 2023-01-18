class rbBidirectionalIterator;
#ifndef RB_ITERATOR_HPP
#define RB_ITERATOR_HPP

#include "rb_tree.hpp"

namespace ft
{
    /** @brief a bidirectional iterator to iter through the rbtree
     * it contains a pointer to a node
     * and a const pointer to the tree to which it belongs*/
    template < class T >
    class rbBidirectionalIterator
    {
        public:
            typedef T                       value_type;
            typedef Node<value_type>        node;
            typedef T*                      pointer;
            typedef T&                      reference;
            typedef typename node::nod_ptr  node_ptr;
            typedef rbTree                  tree_type;

        private:
            node_ptr    _node;          /** node to which the iterator is pointing */
            const tree_type   _tree;    /** the tree to which it belongs */
        

    };
}


#endif