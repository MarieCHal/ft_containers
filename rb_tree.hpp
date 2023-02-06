class rbTree;
#ifndef RB_TREE
#define RB_TREE

#include <functional>
#include <cstddef>
#include "iterator_traits.hpp"
//#include "rb_iterator.hpp"

/** SRCS:   Introduction to algorithms 3rd Edition
 *          https://www.programiz.com/dsa/red-black-tree
 *          https://algorithmtutor.com/Data-Structures/Tree/Red-Black-Trees/
 * 
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
 * - check the return value of ft_insert and rb_delete
 * reinsert nil type in node and rb_tree
 * - why template for copy constructor and not for operator = ? in rbTree
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
        typedef const Node<value_type>* const_node_ptr;

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
        /** @brief a bidirectional iterator to iter through the rbtree
         * it contains a pointer to a node
         * and a const pointer to the tree to which it belongs*/
        class rbBidirectionalIterator
        {
            public:
                typedef T                       value_type;
                typedef Node<value_type>        node;
                typedef T*                      pointer;
                typedef T&                      reference;
                typedef typename node::node_ptr node_ptr;
                typedef typename node::const_node_ptr    const_node_ptr;
                typedef ptrdiff_t               difference_type;
                typedef rbTree                  tree_type;

            private:
                node_ptr            _node;          /** node to which the iterator is pointing */
                const tree_type     *_tree;    /** the tree to which it belongs */
            
            public:
                rbBidirectionalIterator() : _node(NULL), _tree(NULL) {}
                rbBidirectionalIterator(node_ptr node, const tree_type *tree)
                                : _node(node), _tree(tree) {}
                rbBidirectionalIterator(const rbBidirectionalIterator &other) 
                {
                    this->_node = other._node;
                    this->_tree = other._tree;
                }
                virtual ~rbBidirectionalIterator() {}
                // operator == ?
                node_ptr    ptr_node() const {return this->_node;} /** return a pointer to private member _node */
                const tree_type *tree_ptr() const {return this->_tree;} /** return a pointer to priv meber _tree */

                /** @brief prefix incrementation
                 * return the iteraor after incrementation is returned
                 * if _node is one of the end node of the tree the return value */
                rbBidirectionalIterator operator++()
                {
                    if (this->_node == &node::nil)
                        this->_node = this->_tree->rb_min();
                    else
                        this->_node = this->_node->successor();
                    return *this;
                }

                /** @brief postfix incrementation
                 * return the iteraor before the incrementation is returned  */
                rbBidirectionalIterator operator++(int)
                {
                    rbBidirectionalIterator it_before = *this;
                    operator++();
                    return it_before;
                }

                /** @brief prefix decrementation
                 * return the iteraor after incrementation is returned */
                rbBidirectionalIterator operator--()
                {
                    if (this->node == &node::nil)
                        this->_node = this->_tree->maximum();
                    else
                        this->_node = this->_node->predecessor();
                    return *this;
                }

                /** @brief postfix incrementation
                 * return the iteraor before the decrementation is returned  */
                rbBidirectionalIterator operator--(int)
                {
                    rbBidirectionalIterator it_before = *this;
                    operator--();
                    return it_before;
                }

                /** @brief dereferencing the iterator (access to its value) */
                reference operator*() {return this->_node;}

                /** @brief access the value at x */
                pointer operator->() {return &this->_node;}

                /** @brief compares an iterator with this to check if they are equal 
                 * in terms of the stored node */
        };

        class rbBidirectionalConstIterator 
        {
            public:
                typedef T                       value_type;
                typedef T*                      pointer;
                typedef T&                      reference;
                typedef ptrdiff_t               difference_type;
                typedef Node<value_type>        node;
                typedef typename node::node_ptr node_ptr;
                typedef typename node::const_node_ptr const_node_ptr;
                typedef rbTree                  tree_type;

                private:
                node_ptr            _node;          /** node to which the iterator is pointing */
                const tree_type     *_tree;    /** the tree to which it belongs */
            
            public:
                rbBidirectionalConstIterator() : _node(NULL), _tree(NULL) {}
                rbBidirectionalConstIterator(const node_ptr node, const tree_type *tree)
                                : _node(node), _tree(tree) {}
                rbBidirectionalConstIterator(const rbBidirectionalIterator &other) 
                {
                    this->_node = other._node;
                    this->_tree = other._tree;
                }
                virtual ~rbBidirectionalConstIterator() {}
                // operator == ?
                node_ptr    ptr_node() const {return this->_node;} /** return a pointer to private member _node */
                const tree_type *tree_ptr() const {return this->_tree;} /** return a pointer to priv meber _tree */

                /** @brief prefix incrementation
                 * return the iteraor after incrementation is returned
                 * if _node is one of the end node of the tree the return value */
                rbBidirectionalConstIterator operator++()
                {
                    if (this->_node == &node::nil)
                        this->_node = this->_tree->rb_min();
                    else
                        this->_node = this->_node->successor();
                    return *this;
                }

                /** @brief postfix incrementation
                 * return the iteraor before the incrementation is returned  */
                rbBidirectionalConstIterator operator++(int)
                {
                    rbBidirectionalIterator it_before = *this;
                    operator++();
                    return it_before;
                }

                /** @brief prefix decrementation
                 * return the iteraor after incrementation is returned */
                rbBidirectionalConstIterator operator--()
                {
                    if (this->node == &node::nil)
                        this->_node = this->_tree->maximum();
                    else
                        this->_node = this->_node->predecessor();
                    return *this;
                }

                /** @brief postfix incrementation
                 * return the iteraor before the decrementation is returned  */
                rbBidirectionalConstIterator operator--(int)
                {
                    rbBidirectionalConstIterator it_before = *this;
                    operator--();
                    return it_before;
                }

                /** @brief dereferencing the iterator (access to its value) */
                reference operator*() const {return this->_node;}

                /** @brief access the value at x */
                pointer operator->() const {return &this->_node;}

        };

        typedef T                                           value_type; /** pair key/value data stored */
        typedef Node<value_type>                            node;
        typedef std::allocator<Node<T> >                    allocator_type;
        typedef Compare                                     key_compare;
        typedef Node<T>*                                    node_ptr;
        typedef rbBidirectionalIterator                     iterator;
        typedef rbBidirectionalConstIterator                const_iterator;

        /** @brief private member of the class rbtree */
        private:
            node_ptr         _root; /** root node of the tree */
            node_ptr        nil;    /** reference nil node */
            key_compare     _comp;  /** stored key comparator */
            allocator_type  _alloc;

        public:
            rbTree(key_compare compare) : _root(nil), _comp(compare) {} /** constructor */
            rbTree(const rbTree &other)
            {
                this->_comp = other._comp;
                const_iterator it = this->rb_min();
                while (it != other.rb_max())
                    this->rb_insert(*(it++));
            }
            rbTree &operator=(const rbTree &other)
            {
                if (this == &other)
                    return *this;
                this->clear();
                const_iterator it = other.rb_min();
                while (it != other.rb_max())
                    rb_insert(*(it++));
                return *this;
            }

            virtual ~rbTree()
            {
                this->clear();
            }


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
        /** @brief function called to clear and deallocate the whole tree **/
        void    recurse_delete_all(node_ptr Node)
        {
            if (!Node || Node == &nil)
                return;
            recurse_delete_all(Node->l_child);
            recurse_delete_all(Node->r_child);
            _alloc.destroy(Node);
            _alloc.deallocate(Node);
        }

        /** @brief alorithm to maintain red-black tree properties after inserting a new node 
         * the newly inserted node is passed as argument
         * **/
        void    fix_rb_insert(node_ptr newNode)
        {
            node_ptr u;
            while (newNode->parent->c == red)
            {
                if (newNode->parent == newNode->parent->right) /** if newNode is r_child */
                {
                    u = newNode->parent->parent->l_child; /** u = gp l_child of newNode */
                    if (u->c == red)
                    {
                        u->c = black;
                        newNode->parent->c = black;
                        newNode->parent->parent->c = red;
                        newNode = newNode->parent->parent;
                    }
                    else
                    {
                        if (newNode == newNode->parent->l_child)
                        {
                            newNode = newNode->parent;
                            rb_right_rotation(newNode);
                        }
                        newNode->parent->c = black;
                        newNode->parent->parent->c = 1;
                        rb_left_rotation(newNode->parent->parent);
                    }
                }
                else
                {
                    u = newNode->parent->parent->r_child;
                    if (u->c == red)
                    {
                        u->c = black;
                        newNode->parent->c = black;
                        newNode->parent->parent->c = red;
                        newNode = newNode->parent->parent;
                    }
                    else 
                    {
                        if (newNode == newNode->parent->r_child)
                        {
                            newNode = newNode->parent;
                            rb_left_rotation(newNode);
                        }
                        newNode->parent->c = black;
                        newNode->parent->parent->c = red;
                        rb_right_rotation(newNode->parent->parent);
                    }
                }
                if (newNode == this->_root)
                    break;
            }
            this->_root->c = black;
        }

        /** @brief called to maintain the black depth properties of the tree after 
         * deletion if the deleted node was black
         * gettin as argument the node that is at the place of the deletednode (x)
         * */
        void fix_rb_delete(node_ptr x)
        {
            node_ptr s;
            while (x != this->_root && x->c == 0)
            {
                if (x == x->parent->l_child)
                {
                    s = x->parent->r_child;
                    if (s->c  == red)
                    {
                        s->c = black;
                        x->parent->c = red;
                        rb_left_rotation(x->parent);
                        s = x->parent->r_child;
                    }
                    if (s->l_child->c == black && s->r_child->c == black)
                    {
                        s->c = red;
                        x = x->parent;
                    }
                    else
                    {
                        if (s->r_child->c == black)
                        {
                            s->l_child->c = black;
                            s->c = red;
                            rb_right_rotation(s);
                            s = x->parent->r_child;
                        }
                        s->c = x->parent->c;
                        x->parent->c = black;
                        s->r_child->c = black;
                        rb_left_rotation(x->parent);
                        x = this->_root;
                    }
                }
                else
                {
                    s = x->parent->l_child;
                    if (s->c == red)
                    {
                        s->c = black;
                        x->parent->c = red;
                        rb_right_rotation(x->parent);
                        s = x->parent->l_child;
                    }
                    if (s->r_child->c == black && s->r_child->c == black) //???
                    {
                        s->c = red;
                        x = x->parent;
                    }
                    else
                    {
                        if (s->l_child->c == black)
                        {
                            s->r_child->c = black;
                            s->c = red;
                            rb_left_rotation(s);
                            s = x->parent->l_child;
                        }
                        s->c = x->parent->c;
                        x->parent->c = black;
                        s->l_child->c = black;
                        rb_right_rotation(x->parent);
                        x = this->_root;
                    }
                }
            }
            x->c = black;
        }

        void rbTransplant(node_ptr oldNode, node_ptr newNode)
        {
            if (oldNode->parent == &nil)
                this->_root = newNode;
            else if (oldNode == oldNode->parent->l_child)
                oldNode->parent->l_child = newNode;
            else
                oldNode->parent->r_child = newNode;
            newNode->parent = oldNode->parent;
        }



        public:
            /** @brief finds the minimum value of the tree by calling the minimum
             * function of the root node */
            iterator rb_min() {return this->_root->minimum();}
            const_iterator rb_min() const {return this->_root->minimum();}

            /** @brief finds the minimum value of the tree by calling the minimum
             * function of the root node */
            iterator rb_max() {return this->_root->maximum();}

            void clear()
            {
                this->recurse_delete_all(this->_root);
                this->_root = &nil;
            }

            node_ptr rb_search(const value_type &value)
            {
                node_ptr Node;
                while (Node != &nil)
                {
                    if (this->_comp(value, Node->data)) /** if searched value is smaller than data of the node */
                        Node = Node->l_child;
                    else if (this->_com(Node->data, value))
                        Node = Node->r_child;
                    else /** if value equals data */
                        return Node;
                }
                return Node;
            }

            /** @brief swaps trees */
            void    rb_swap(rbTree &other)
            {
                node_ptr tmp = this->_root;
                this->_root = other._root;
                other._root = tmp;
            }

            /** @brief inserting an element in the red-black tree 
             * get as arument a pair key-value pair
             * return an ft pairs 
            */
            ft::pair<iterator, bool>    rb_insert(value_type data)
            {
                node_ptr tmpNode = this->_root; /** starting at the top of the tree */
                node_ptr newNodeP = &nil;
                while (tmpNode != &nil) /** going through the tree to find the apropriate place to insert newNode */
                {
                    newNodeP = tmpNode; /** keeping track the last node */
                    if (_comp(data, tmpNode->data)) /** if data is smaller than data of tmpNode */
                        tmpNode = tmpNode->l_child;
                    else if (_comp(tmpNode->data, data)) /** else go right */
                        tmpNode = tmpNode->r_child;
                    else
                        return ft::make_pair(iterator(tmpNode, this), false);
                }
                // newNodeP = tmpNode->parent;
                node dataNode(data); /** create a Node containing key/value pair */
                node_ptr newNode = _alloc.allocate(1);
                _alloc.construct(newNode, dataNode);
                newNode->parent = newNodeP;
                if (newNodeP == &nil)
                    this->_root = newNode;
                else if (_comp(data, newNodeP->data))
                    newNodeP->l_child = newNode;
                else
                    newNode->r_child = newNode;
                newNode->l_child = &nil;
                newNode->r_child = &nil;
                newNode->c = red;
                fix_rb_insert(newNode);
                return ft::make_pair(iterator(newNode, this), true);
            }

            bool    rb_delete(node_ptr node)
            {
                if (!node || node == &nil) /** an end node can't be deleted */
                    return false;
                node_ptr a = node; /** copy of node */
                node_ptr b = node; /** copy of node */
                node_ptr c;
                color node_color = node->c;
                if (b->l_child == &nil)
                {
                    c = b->r_child;
                    rbTransplant(b, b->r_child);
                }
                else if (b->r_child == &nil)
                {
                    c = b->l_child;
                    rbTransplant(b, b->l_child); /** transplant b descendent to its left child */
                }
                else
                {
                    a = b->r_child->minimum();
                    node_color = a->c;
                    c = a->r_child;
                    if (b->parent == b)
                        a->parent = b;
                    else
                    {
                        rbTransplant(a, a->r_child);
                        a->r_child = b->r_child;
                        b->r_child->parent = a;
                    }
                    rbTransplant(b, a);
                    a->l_child = b->l_child;
                    b->l_child->parent = a;
                    a->c = b->c;
                }
                if (node_color == black)
                    fix_rb_delete(c);
                _alloc.destroy(b);
                _alloc.deallocate(c, 1);
                return true;
            }

    };

};

#endif