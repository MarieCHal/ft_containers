#ifndef TEST_HPP
#define TEST_HPP

#include <stdio.h>
#include <iostream>
#include "pair.hpp"

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

        static node nil;
        
        Node() : data(), parent(NULL), r_child(NULL), l_child(NULL), c(black) {} /** construct an empty node */
        Node(const Node &other) {*this = other;} /** copy constructor */
        Node(value_type data) : data(data), parent(NULL), r_child(NULL), l_child(NULL), c(black) {} /** construct node with value stored */
        Node &operator=(const Node &other) /** operator oveload */
        {
            //ft::pair<rhs.data.first, rhs.data.seccond> test = rhs.data;
            this->data = other.data;
            this->parent = other.parent;
            this->r_child = other.r_child;
            this->l_child = other.l_child;
            this->c = other.c;
            return *this;
        }

        /** member functions that facilitate operation and access to data on rbtree*/

        /** @brief returns the node in which the smallest value of the tree is stored
         * i.e the far most left child of the root node stops when it reaches
         * a &nil node
         * needed to iterate through the tree and tree operations*/
        node_ptr    minimum()
        {
            node_ptr min = this;
            //node &nil = &nil_function();
            if (this == &nil)
                return min;
            while (min->l_child != &nil)
                min = min->l_child;
            return (min);
        }

        const_node_ptr    minimum() const 
        {
            const_node_ptr min = this;
            //node &nil = &nil_function();
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
            //node &nil = &nil_function();
            if (this == &nil)
                return max;
            while (max->r_child != &nil)
                max = max->r_child;
            return (max);
        }

        const_node_ptr    maximum() const
        {
            const_node_ptr max = this;
            //node &nil = &nil_function();
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
            if (this == &nil)
                return this;
            node_ptr r = this->r_child; 
            if (r != &nil)
                return r->minimum(); /** if r_child return the min starting from the r_child of the node */
            node_ptr p = this->parent;
            node_ptr x = this;
            while (p != &nil && x == p->r_child)
            {
                x = p;
                p = p->parent;
            }
            return p; // go up the tree until parent node if found or r isn't the right child of p
        }

        const_node_ptr    successor() const
        {
            if (this == &nil)
                return this;
            const_node_ptr r = this->r_child; 
            if (r != &nil)
                return r->minimum(); /** if r_child return the min starting from the r_child of the node */
            const_node_ptr p = this->parent;
            const_node_ptr x = this;
            while (p != &nil && x == p->r_child)
            {
                x = p;
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
            if (this == &nil)
                return this;
            node_ptr l = this->l_child;
            if (l != &nil)
                return l->maximum(); /** if l_child return the max starting from the l_child of the node */
            node_ptr p = this->parent;
            node_ptr x = this;
            while (p != &nil && x == p->l_child)
            {
                ////std::cout << "ok predecessor\n" ;
                x = p;
                p = p->parent;
            }
            return p; // go up the tree until parent node if found or r isn't the left child of p
        }

        const_node_ptr    predecessor() const
        {
            if (this == &nil)
                return this;
            const_node_ptr l = this->l_child;
            if (l != &nil)
                return l->maximum(); /** if l_child return the max starting from the l_child of the node */
            const_node_ptr p = this->parent;
            const_node_ptr x = this;
            while (p != &nil && x == p->l_child)
            {
                ////std::cout << "ok predecessor\n" ;
                x = p;
                p = p->parent;
            }
            return p; // go up the tree until parent node if found or r isn't the left child of p
        }

    };

    template<class T>
	Node<T> Node<T>::nil = Node<T>();

    /** @brief operator oveload to compare nodes with node of type &nil */
    template< class T>
    bool operator==(const Node<T>& rhs, const Node<T>& lhs)
    {
        if (rhs.data == lhs.data && rhs.parent == lhs.parent && rhs.l_child == lhs.l_child 
                && rhs.r_child == lhs.r_child && rhs.c == lhs.c)
            return true;
        return false;
    }

    template <class T>
    bool operator!=(const Node<T>& rhs, const Node<T>& lhs)
    {
        if (!(rhs == lhs))
            return true;
        else
           return false;
    }


    template<class T, class Container, class Compare = std::less<T>  >
    class rbTree
    {
        /** @brief a bidirectional iterator to iter through the rbtree
         * it contains a pointer to a node
         * and a const pointer to the tree to which it belongs*/
        template<class N>
        class rbBidirectionalIterator
        {
            public:
                typedef N                                   value_type; /** key/vaue pair type*/
                typedef Node<value_type>                    node;
                typedef N*                                  pointer;
                typedef N&                                  reference;
                typedef typename node::node_ptr             node_ptr;
                typedef typename node::const_node_ptr       const_node_ptr;
                typedef ptrdiff_t                           difference_type;
                typedef struct bidirectional_iterator_tag   iterator_category;
                typedef rbTree                              tree_type;

            private:
                node_ptr            _node;          /** node to which the iterator is pointing */
                const tree_type     *_tree;    /** the tree to which it belongs */
            
            public:
                rbBidirectionalIterator() : _node(NULL), _tree(NULL) {}
                rbBidirectionalIterator(node_ptr node, const tree_type *tree)
                                : _node(node), _tree(tree) {}
                rbBidirectionalIterator(const rbBidirectionalIterator &other) 
                {
                    this->_node = other.base();
                    this->_tree = other.tree_ptr();
                }

                rbBidirectionalIterator& operator=(const rbBidirectionalIterator &other)
                {
                    this->_node = other.base();
                    this->_tree = other.tree_ptr();
                    return *this;
                }

                virtual ~rbBidirectionalIterator() {}
                
                node_ptr    base() const {return this->_node;} /** return a pointer to private member _node */
                const tree_type *tree_ptr() const {return this->_tree;} /** return a pointer to priv meber _tree */

                /** @brief prefix incrementation
                 * return the iteraor after incrementation is returned
                 * if _node is one of the end node of the tree the return value */
                rbBidirectionalIterator operator++()
                {
                    //node &nil = this->_node.&nil_function();
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
                    if (this->_node == &node::nil)
                        this->_node = this->_tree->rb_max();
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

                friend bool operator==(const rbBidirectionalIterator &lhs, const rbBidirectionalIterator &rhs)
                {
                    return lhs._node == rhs._node;
                }

                friend bool operator!=(const rbBidirectionalIterator &lhs, const rbBidirectionalIterator &rhs)
                {
                    return !(lhs._node == rhs._node);
                }

                /** @brief dereferencing the iterator (access to its value) */
                reference operator*() {return this->_node->data;}
                reference operator*() const {return this->_node->data;}

                /** @brief access the value at x */
                pointer operator->() {return &(this->_node->data);}
                pointer operator->() const {return &(this->_node->data);}

                /** @brief compares an iterator with this to check if they are equal 
                 * in terms of the stored node */

        }; //bidirectional iterator

        template<class N>
        class rbBidirectionalConstIterator 
        {
            public:
                typedef N                                           value_type;
                typedef const N*                                    pointer;
                typedef const N&                                    reference;
                typedef ptrdiff_t                                   difference_type;
                typedef struct bidirectional_iterator_tag           iterator_category;
                //typedef Node<value_type>                    node;
                //typedef typename node::node_ptr             node_ptr;
                //typedef typename node::const_node_ptr       const_node_ptr;
                typedef rbBidirectionalIterator<N>                  iterator;
                typedef typename iterator::node                     node;
                typedef typename iterator::node_ptr                 node_ptr;
                typedef typename iterator::const_node_ptr           const_node_ptr;
                typedef rbTree                                      tree_type;

                private:
                const_node_ptr              _node;          /** node to which the iterator is pointing */
                const tree_type             *_tree;    /** the tree to which it belongs */
            
            public:
                rbBidirectionalConstIterator() : _node(NULL), _tree(NULL) {}
                rbBidirectionalConstIterator(const const_node_ptr node, const tree_type *tree)
                                : _node(node), _tree(tree) {}
                rbBidirectionalConstIterator(const rbBidirectionalConstIterator &other) 
                {
                    this->_node = other.base();
                    this->_tree = other.tree_ptr();
                }
                rbBidirectionalConstIterator(const iterator &other) {
                    this->_node = other.base();
                    this->_tree = other.tree_ptr();
                }
                rbBidirectionalConstIterator& operator=(const rbBidirectionalConstIterator &other)
                {
                    this->_node = other.base();
                    this->_tree = other.tree_ptr();
                    return *this;
                }
                virtual ~rbBidirectionalConstIterator() {}

                const_node_ptr    base() const {return this->_node;} /** return a pointer to private member _node */
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
                    rbBidirectionalConstIterator it_before = *this;
                    operator++();
                    return it_before;
                }

                /** @brief prefix decrementation
                 * return the iteraor after incrementation is returned */
                rbBidirectionalConstIterator operator--()
                {
                    if (this->_node == &node::nil)
                        this->_node = this->_tree->rb_max();
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

                friend bool operator==(const rbBidirectionalConstIterator &lhs, const rbBidirectionalConstIterator &rhs)
                {
                    return lhs._node == rhs._node;
                }

                friend bool operator!=(const rbBidirectionalConstIterator &lhs, const rbBidirectionalConstIterator &rhs)
                {
                    return !(lhs._node == rhs._node);
                }

                /** @brief dereferencing the iterator (access to its value) */
                reference operator*() const {return this->_node->data;}

                /** @brief access the value at x */
                pointer operator->() const {return &(this->_node->data);}

        };

        public:
            typedef T                                                       value_type; /** pair key/value data stored */
            typedef Node<value_type>                                        node;
            typedef std::allocator<Node<T> >                                allocator_type;
            typedef Compare                                                 key_compare;
            typedef Node<T>*                                                node_ptr;
            typedef const Node<T>*                                          const_node_ptr;
            typedef rbBidirectionalIterator<value_type>                     iterator;
            typedef rbBidirectionalConstIterator<value_type>                const_iterator;

        /** @brief private member of the class rbtree */
        private:
            node_ptr         _root; /** root node of the tree */
            key_compare     _comp;  /** stored key comparator */
            allocator_type  _alloc;
            //node            &nil;

        public:
            rbTree(key_compare compare) : _root(&node::nil), _comp(compare) {
                //this->&nil = this->_root->&nil_function();
                //_root = &node::nil;
            }
             /** constructor */
            rbTree(const rbTree &other) : _root(&node::nil), _comp(other._comp)
            {
                *this = other;
            }
            rbTree &operator=(const rbTree &other)
            {
                if (this == &other)
                    return *this;
                this->clear();
                const_iterator it = other.rb_begin();
                while (it != other.rb_end())
                    rb_insert(*(it++));
                return *this;
            }

            virtual ~rbTree()
            {
                this->clear();
            }


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
                if (x == &node::nil)
                    return ;
                node_ptr y = x->r_child;
                x->r_child = y->l_child;
                if (y->l_child != &node::nil) 
                    y->l_child->parent = x; 
                y->parent = x->parent;
                if (x->parent == &node::nil)   
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
                if (!x)
                    return ;
                node_ptr y = x->l_child;
                x->l_child = y->r_child;
                if (y->r_child != &node::nil) 
                    y->r_child->parent = x; 
                y->parent = x->parent;
                if (x->parent == &node::nil)   
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
            if (!Node || Node == &node::nil)
                return;
            recurse_delete_all(Node->l_child);
            recurse_delete_all(Node->r_child);
            _alloc.destroy(Node);
            _alloc.deallocate(Node, 1);
        }


        void    fix_rb_insert(node_ptr newNode) //z
        {
            ////std::cout << "fix rb insert\n";
            ////std::cout << "newNode key: " << newNode->data.first << ", color: " << newNode->c << std::endl;
            node_ptr u ;
            while (newNode->parent->c == red)
            {
                if (newNode->parent == newNode->parent->parent->l_child) /** if newNode parent's is the left child of newNode gp*/
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
                else
                {
                    u = newNode->parent->parent->l_child;
                    ////std::cout << "u key: " << u->data.first << ", color: " << u->c << std::endl;
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
                        newNode->parent->parent->c = red;
                        rb_left_rotation(newNode->parent->parent);
                    }
                }
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
            if (oldNode->parent == &node::nil)
                this->_root = newNode;
            else if (oldNode == oldNode->parent->l_child)
                oldNode->parent->l_child = newNode;
            else
                oldNode->parent->r_child = newNode;
            newNode->parent = oldNode->parent;
        }


        node_ptr rb_min() {return this->_root->minimum();}
        node_ptr rb_max() {return this->_root->maximum();}

        /** needed const equivalent for iterator */
        node_ptr rb_min() const {return this->_root->minimum();}
        node_ptr rb_max() const {return this->_root->maximum();}

        public:
            /** @brief finds the minimum value of the tree by calling the minimum
             * function of the root node */
            iterator rb_begin() { return (iterator(this->_root->minimum(), this));}
            const_iterator rb_begin() const {return const_iterator(this->_root->minimum(), this);}

            /** @brief finds the minimum value of the tree which are the &nil nodes*/
            iterator rb_end() {return iterator(&node::nil, this); }

            const_iterator rb_end() const { 
                return const_iterator(&node::nil, this);
                }

            node_ptr lower_bound(const value_type &val)
            {
                node_ptr tmp = this->_root;
                node_ptr tmp2(tmp);
                while (tmp != &node::nil)
                {
                    tmp2 = tmp;
                    if (this->_comp(val, tmp->data))
                        tmp = tmp->l_child;
                    else if (this->_comp(tmp->data, val))
                        tmp = tmp->r_child;
                    else
                        return tmp;
                }
                if (this->_comp(val, tmp2->data))
                    return tmp2;
                return tmp2->successor();
            }

            const_node_ptr lower_bound(const value_type &val) const
            {
                const_node_ptr tmp = this->_root;
                const_node_ptr tmp2(tmp);
                while (tmp != &node::nil)
                {
                    tmp2 = tmp;
                    if (this->_comp(val, tmp->data))
                        tmp = tmp->l_child;
                    else if (this->_comp(tmp->data, val))
                        tmp = tmp->r_child;
                    else
                        return tmp;
                }
                if (this->_comp(val, tmp2->data))
                    return tmp2;
                return tmp2->successor();
            }

            node_ptr upper_bound(const value_type &val)
            {
                node_ptr tmp = this->_root;
                node_ptr tmp2(tmp);
                while (tmp != &node::nil)
                {
                    tmp2 = tmp;
                    if (this->_comp(val, tmp->data))
                        tmp = tmp->l_child;
                    else if (this->_comp(tmp->data, val))
                        tmp = tmp->r_child;
                    else
                        return tmp->successor();
                }
                if (this->_comp(val, tmp2->data))
                    return tmp2;
                return tmp2->successor();
            }

            const_node_ptr upper_bound(const value_type &val) const
            {
                const_node_ptr tmp = this->_root;
                const_node_ptr tmp2(tmp);
                while (tmp != &node::nil)
                {
                    tmp2 = tmp;
                    if (this->_comp(val, tmp->data))
                        tmp = tmp->l_child;
                    else if (this->_comp(tmp->data, val))
                        tmp = tmp->r_child;
                    else
                        return tmp->successor();
                }
                if (this->_comp(val, tmp2->data))
                    return tmp2;
                return tmp2->successor();
            }

            void clear()
            {
                this->recurse_delete_all(this->_root);
                this->_root = &node::nil;
            }

            node_ptr rb_search(const value_type &value)
            {
                node_ptr Node = this->_root;
                while (Node != &node::nil)
                {
                    if (this->_comp(value, Node->data)) /** if searched value is smaller than data of the node */
                        Node = Node->l_child;
                    else if (this->_comp(Node->data, value))
                        Node = Node->r_child;
                    else /** if value equals data */
                        return Node;
                }
                //std::cout << "ok value rb_search\n";
                return Node;
            }

            const_node_ptr rb_search(const value_type &value) const
            {
                const_node_ptr Node = this->_root;
                while (Node != &node::nil)
                {
                    if (this->_comp(value, Node->data)) /** if searched value is smaller than data of the node */
                        Node = Node->l_child;
                    else if (this->_comp(Node->data, value))
                        Node = Node->r_child;
                    else /** if value equals data */
                        return Node;
                }
                //std::cout << "ok value rb_search\n";
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
                //std::cout << " rb_insert \n";
                node_ptr tmpNode = this->_root; /** starting at the top of the tree */
                node_ptr newNodeP = &node::nil;
                while (tmpNode != &node::nil) /** going through the tree to find the apropriate place to insert newNode */
                {   
                    //std::cout << "tmpNode: " << tmpNode->data.first << std::endl;
                    //std::cout << "data: " << data.first << std::endl; 
                    newNodeP = tmpNode; /** keeping track the last node */
                    if (_comp(data, tmpNode->data)) /** if data.first is smaller than data.first of tmpNode */
                    {
                        tmpNode = tmpNode->l_child;
                        //std::cout << "if 1\n" << std::endl;
                    }
                    else if (_comp(tmpNode->data, data)) /** else go right */
                    {
                        tmpNode = tmpNode->r_child;
                        //std::cout << "if 2\n" << std::endl;
                    } 
                    else
                    {
                        //std::cout << "else return \n" << std::endl;
                        return ft::make_pair(iterator(tmpNode, this), false);
                    }
                }
                node dataNode(data); /** create a Node containing key/value pair */
                node_ptr newNode = _alloc.allocate(1);
                _alloc.construct(newNode, dataNode);
                newNode->parent = newNodeP;
                if (newNodeP == &node::nil)
                    this->_root = newNode;
                else if (_comp(data, newNodeP->data))
                {
                    //std::cout << "l_child data: " << data.first << " newNodeP " << newNodeP->data.first << std::endl; 
                    newNodeP->l_child = newNode;
                }
                else
                {
                    //std::cout << "r_child data: " << data.first << " newNodeP " << newNodeP->data.first << std::endl; 
                    newNodeP->r_child = newNode;
                }
                newNode->l_child = &node::nil;
                newNode->r_child = &node::nil;
                newNode->c = red;
                fix_rb_insert(newNode);
                //std::cout << "newNode key: " << newNode->data.first << ", color: " << newNode->c << std::endl;
                //std::cout << "newNode l_child: " << newNode->l_child->data.first << std::endl;
                //std::cout << "newNode r_child: " << newNode->r_child->data.first << std::endl;
                //std::cout << "newNode parent: " << newNode->parent->data.first << std::endl;
                return ft::make_pair(iterator(newNode, this), true);
            }

            bool    rb_delete(node_ptr node)
            {
                if (!node || node == &node::nil) /** an end node can't be deleted */
                    return false;
                node_ptr a = node; /** copy of node */
                node_ptr b = node; /** copy of node */
                node_ptr c;
                color node_color = node->c; /** sotre the original color of the node to be deleted */
                if (b->l_child == &node::nil)
                {
                    c = b->r_child;
                    rbTransplant(b, b->r_child);
                }
                else if (b->r_child == &node::nil)
                {
                    c = b->l_child;
                    rbTransplant(b, b->l_child); /** transplant b descendent to its left child */
                }
                else
                {
                    a = b->r_child->minimum();
                    node_color = a->c;
                    c = a->r_child;
                    if (a->parent == b)
                        c->parent = a;
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
                _alloc.deallocate(b, 1);
                return true;
            }

    }; //rbTree
}

#endif