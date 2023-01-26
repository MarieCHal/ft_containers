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
            typedef typename node::node_ptr  node_ptr;
            typedef rbTree                  tree_type;

        private:
            node_ptr            _node;          /** node to which the iterator is pointing */
            const tree_type     _tree;    /** the tree to which it belongs */
        
        public:
            rbBidirectionalIterator() : _node(NULL), _tree(NULL) {}
            rbBidirectionalIterator(node_ptr node, const tree_type *tree)
                            : node(node), tree_type(node) {}
            rbBidirectionalIterator(const rbBidirectionalIterator &other) 
            {
                this->_node = other._node;
                this->_tree = other._tree;
            }
            // operator == ?
            node_ptr    node_ptr() const {return this->_node;} /** return a pointer to private member _node */
            const tree_type *tree_ptr() const {return this->_tree;} /** return a pointer to priv meber _tree */

            /** @brief prefix incrementation
             * return the iteraor after incrementation is returned
             * if _node is one of the end node of the tree the return value */
            rbBidirectionalIterator &operator++()
            {
                if (this->_node == &node::nil)
                    this->_node = this->_tree->rb_min();
                else
                    this->_node = this->_node->successor();
                return *this;
            }

            /** @brief postfix incrementation
             * return the iteraor before the incrementation is returned  */
            rbBidirectionalIterator &operator++(int)
            {
                rbBidirectionalIterator it_before = *this;
                operator++();
                return it_before;
            }

            /** @brief prefix decrementation
             * return the iteraor after incrementation is returned */
            rbBidirectionalIterator &operator--()
            {
                if (this->node == &node_type::nil)
                    this->_node = this->_tree->maximum();
                else
                    this->_node = this->_node->predecessor();
                return *this;
            }

            /** @brief postfix incrementation
             * return the iteraor before the decrementation is returned  */
            rbBidirectionalIterator &operator++(int)
            {
                rbBidirectionalIterator it_before = *this;
                operator--();
                return it_before;
            }

            /** @brief dereferencing the iterator (access to its value) */
            reference operator*() {return this->_node;}

            /** @brief 

    };
}


#endif