class rbTree;
#ifndef RB_TREE
#define RB_TREE

#include <functional>
#include <cstddef>
#include "iterator_traits.hpp"
#include "rb_iterator.hpp"

/** SRCS:   Introduction to algorithms 3rd Edition
 *          https://www.programiz.com/dsa/red-black-tree
 * 
 * @brief a red balck three is a self balacing binary search three
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
 * - maybe an operator oveload for == on node?
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
     * */
    template <class T>
    struct Node
    {
        typedef T                       value_type; /** the value type of the stored data */
        typedef Node<value_type>        node;       /** a node of type T*/
        typedef Node<value_type>*       node_ptr;      /** ptr of type node<T> */

        /** elements contained in a node */
        T                               data;    /** data stored(map element) */
        node_ptr                        parent;  /** pointer to parent node */
        node_ptr                        r_child; /** pointer to right child node */
        node_ptr                        l_child; /** pointer to left child node */
        color                           c;

         /** an empty node example used to compare nodes (used to find min) 
          * nil being the keyword to represent emty nodes present at the end of
          * the tree (similar to NULL)
         */
        static node nil;

        Node() : data(), parent(NULL), r_child(NULL), l_child(NULL), c(red) {} /** construct an empty node */
        Node(const Node &other) {*this = other;} /** copy constructor */
        Node(value_type data) : data(data), parent(NULL), r_child(NULL), l_child(NULL), c(red) {} /** construct node with value stored */
        Node &operator=(const Node &other) /** operator oveload */
        {
            this->data = other.data;
            this->parent = other.parent;
            this->r_child = other.r_child;
            this->l_child = other.l_child;
            this->color = other.color;
            return *this;
        }

        /** member functions that facilitate operation and access to data on rbtree*/

        /** @brief returns the node in which the smallest value of the tree is stored
         * i.e the far most left child of the root node stops when it reaches
         * a nil node
         * needed to iterate through the tree and tree operations*/
        node_ptr    minimum()
        {
            node_ptr min = this;
            if (this == &nil)
                return min;
            while (min->l_child != &nil)
                min = min->l_child;
            return (min);
        }

        /** @brief returns the node in which the bigger value of the tree is stored
         * ie. the far most right child of the node
         * needed to iterate through the tree and tree operations
        */
        node_ptr    maximum()
        {
            node_ptr max = this;
            if (this == &nil)
                return max;
            while (max->r_child != &nil)
                max = max->r_child;
            return (max);
        }

        /** @brief returns the node in which the closest bigger value in the tree is stored (p.290) 
         * example: map[4, 7, 8, 10, 6] -> succesor of 6 is 4
         * needed to iterate through the tree
        */
        node_ptr    successor()
        {
            node_ptr r = this->r_child; 
            if (r != nil)
                return r->minimum(); /** if r_child return the min starting from the r_child of the node */
            node_ptr p = this->parent;
            while (p != nil && r == p->r_child)
            {
                r = p;
                p = p->parent;
            }
            return p; // go up the tree until parent node if found or r isn't the right child of p
        }

        /** @brief returns the node in which the closest smaller value in the tree is stored (p.290) 
         * example: map[4, 7, 8, 10, 6] -> succesor of 6 is 7
         * needed to iterate through the tree
        */
        node_ptr    predecessor()
        {
            node_ptr l = this->l_child;
            if (l != nil)
                return l->maximum(); /** if l_child return the max starting from the l_child of the node */
            node_ptr p = this->parent;
            while (p != nil && l == p->l_child)
            {
                l = p;
                p = p->parent;
            }
            return p; // go up the tree until parent node if found or r isn't the left child of p
        }

    };

    template<class T>
    Node<T> Node<T>::nil = Node<T>();

    template<class T, class Compare = std::less<T> >
    class rbTree
    {
        /** @brief biderectional iterator needed to iter through the map
        class rbIterator
        {
            public:
                typedef struct bidirectional_iterator_tag   iterator_category;
                typedef ptrdiff_t                           difference_type;
                typedef T                                   value_type;
                typedef T*                                  pointer;
                typedef T&                                  reference;
                typedef std::allocator<Node>

        }; */

        typedef T                                           value_type; /** pair key/value data stored */
        typedef std::allocator<Node<T> >                    allocator_type;
        typedef Compare                                     key_compare;
        typedef Node<T>*                                    node_ptr;
        typedef rbBidirectionalIterator<value_type>         iterator;

        

        /** @brief private member of the class rbtree */
        private:
            node_ptr         _root; /** root node of the tree */
            node_ptr        nil;    /** reference nil node */
            key_compare     _comp;  /** stored key comparator */
            allocator_type  _alloc;

        public:
            rbTree() : _root(NULL), nil(NULL) {} /** constructor */

        public:
        /** @brief inserting a new node:
         * a new node is always inserted and colored red
         * if it violates the red-black tree properties than the following operations are executed:
         * 1. Recolor
         * 2. Rotation
         * */
        private:
            /** @brief left rotation 
             * The arrangement on the nodes on the right is transformed into the 
             * arrangements on the left node
             * rotation between node x and its right child node y
             *      x                   y
             *         \      =>       /    
             *            y           x 
             * **/
            void rb_left_rotation(node_ptr x)
            {
                if (x == &nil)
                    return ;
                node_ptr y = x->r_child;
                x->r_child = y->l_child;
                if (y->l_child != &nil) 
                    y->l_child->parent = x; 
                y->parent = x->parent;
                if (x->parent == NULL)   
                    this->_root = y;
                else if (x == x->parent->l_child)
                    x->parent->l_child = y;
                else
                    x->parent->r_child = y;
                y->l_child = x;
                x->parent = y;          
            }

            /** @brief right rotation 
             * The arrangement on the nodes on the left is transformed into the 
             * arrangements on the rigth node
             * rotation between node x and its left child node y
             *           x                  y
             *          /       =>             \
             *         y                        x
             * **/
            void rb_right_rotation(node_ptr x)
            {
                if (x == &nil)
                    return ;
                node_ptr y = x->l_child;
                x->l_child = y->r_child;
                if (y->r_child != &nil) 
                    y->r_child->parent = x; 
                y->parent = x->parent;
                if (x->parent == NULL)   
                    this->_root = y;
                else if (x == x->parent->r_child)
                    x->parent->r_child = y;
                else
                    x->parent->l_child = y;
                y->r_child = x;
                x->parent = y;
            }


        /** @brief alorithm to maintain red-black tree properties after inserting a new node **/

        public:
            /** @brief finds the minimum value of the tree by calling the minimum
             * function of the root node */
            node_ptr rb_min() {return this->_root->minimum();}

            /** @brief finds the minimum value of the tree by calling the minimum
             * function of the root node */
            node_ptr rb_max() {return this->_root->maximum();}

            /** @brief swaps trees */
            void    rb_swap(rbTree &other)
            {
                node_ptr tmp = this->_root;
                this->_root = other._root;
                other._root = tmp;
            }
            /** @brief inserting an element in the red-black tree */
            void    rb_insert(node_ptr newNode)
            {
                if (this->_root == &nil)
                {
                    this->_root = newNode;
                    this->_root->c = black;
                    return ;
                }
                if (newNode->data > this->_root->data)
                    newNode->parent = this->_root->data.maximum();
                else 
                    newNode->parent = this->_root->data.minimum();
                if (newNode->data > newNode->parent->data)
                    newNode->parent->r_child = newNode;
                else
                    newNode->parent->l_child = newNode;
                newNode->color = red;
        }

    };

};

#endif