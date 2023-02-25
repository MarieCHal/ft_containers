#ifndef FT_MAP_HPP
#define FT_MAP_HPP

//============ INCLUDES ===============
#include <memory>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstddef>
#include <stdexcept>
#include <functional>
#include "algorithm.hpp"
#include "enable_if.hpp"
#include "reverse_iterator.hpp"
#include "distance.hpp"
#include "pair.hpp"
#include "test.hpp"

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
            typedef ft::rbTree<ft::pair<Key, T>, value_compare>                     tree_val;

        
        public: 
            /** @brief a bidirectional iterator to value_type
             * that can read or modify any eleent stored*/
            typedef typename tree_val::iterator                         iterator;
            typedef typename tree_val::const_iterator                   const_iterator;
            typedef reverse_iterator<iterator>                 reverse_iterator; /** reverse iterator on the model of rb_iterator */
            //typedef reverse_iterator<const_iterator>     const_reverse_iterator;
    
        private:

            key_compare                                     _comp;
            allocator_type                                  _alloc;
            tree_val                                        _tree;
            size_t                                          _size;  

        public:
            
            /** @brief default constructor */
            explicit map(const key_compare &comp = key_compare(),
                            const allocator_type &alloc = allocator_type())
                            : _comp(comp), _alloc(alloc), _tree(value_compare(comp)), _size(0) {}              
            
            /** @brief construct the map with content from first to last */
            template< class InputIt>
            map ( InputIt first, InputIt last, 
                    const key_compare &comp = key_compare(),
                    const allocator_type &alloc = allocator_type())
                    : _comp(comp), _alloc(alloc), _tree(value_compare(comp)), _size(0)
                    {
                        //std::cout << "map iterator contructor" << std::endl;
                        this->insert(first, last);
                    }
            
            map (const map &other) : _tree(other._tree)
            {
                //std::cout << "map contructor by copy" << std::endl;
                this->_size = other._size;
                this->_comp = other._comp;
                this->_alloc = other._alloc;
            }

            /** @brief destructor, calls also the destructors of its members (iterator and tree)*/
            virtual ~map() {}

            map& operator=(const map &other)
            {
                //std::cout << "map operator = " << std::endl;
                this->clear();
                this->insert(other.begin(), other.end());
                this->_size = other._size;
                this->_comp = other._comp;
                this->_alloc = other._alloc;
            }

            /** @brief returns the associated allocator */
            allocator_type get_allocator() const { return this->_alloc;}

            /*************** ELEMENT ACCESS ***************/
            /** @brief take a key as argument and returns the corresponding value stored if 
             * found in the map, else it throws an out of range exception 
            */
            mapped_type& at( const key_type &key)
            {
                iterator at = this->find(key);
                if (at == this->end())
                    throw std::out_of_range(" Key not found in map");
                else
                    return at->second;
            }

            /** @brief returns a reference to the stored value by searching the key, if not found
             * insert a new key value pair and return the newly inserted value
            */
            mapped_type& operator[](const key_type& key)
            {
                iterator it = this->insert(ft::make_pair(key, mapped_type())).first;
                return (*it).second;
            }

            /**************** ITERATORS ****************/

            /** @brief an iterator to the smallest key stored in the map, which is considered
             * as the begining of the map */
            iterator begin() { return this->_tree.rb_begin();}
            const_iterator begin() const { return this->_tree.rb_begin();}

            iterator end() { return this->_tree.rb_end();}
            const_iterator end() const { return this->_tree.rb_end();}

            reverse_iterator rbegin() {return reverse_iterator(this->end());}
            //const_reverse_iterator rbegin() const {return (this->_tree->rb_max() - 1);}

            reverse_iterator rend() { return reverse_iterator(this->begin());}
            //const_reverse_iterator rend() { return (this->_tree->rb_min() - 1);}


            /***************** CAPACITY *****************/
            bool empty() const { 
                if ( this->_size == 0)
                    return true;
                else 
                    return false;
            }

            size_type size() const { return this->_size;}
            //size_type max_size() const {}

            /***************** MODIFIERS *****************/
            void clear() {
                this->_tree.clear();
                this->_size = 0;
            }

            /** @brief inserts the element value (key/value pair) into the map
             * returns an iterator/bool pair
             * -> if the insertion was succesful the iterator is pointing to the newly inserted 
             * data and the bool is set to true
             * -> else if the key already exists in the map the element is not inserted
             * the iterator then correspond to the existing key and the bool set to false 
            */
            ft::pair<iterator, bool> insert(const value_type &value)
            {
                //std::cout << " insert1 -> begin\n";
                ft::pair<iterator, bool> res = this->_tree.rb_insert(value);
                if (res.second == true)
                    this->_size++;
                //std::cout << " insert1 -> end\n";
                return res;
            }

            /** @brief iterator pos specfies from where the searching operation for insertion is to
             * be done to accelerate the process
            */
            iterator insert(iterator pos, const value_type &value) 
            {
                //std::cout << " insert2\n";
                (void) pos;
                return (insert(value)).first;
            }

            /** @brief inserts in the map the elements contained between first and last
             * has undefined behavior if elements in the range have keys that compare 
             * equivalent */
            template<class InputIt>
            void insert( InputIt first, InputIt last)
            {
                //std::cout << "insert3\n";
                for (;first != last ; first++)
                    this->insert(*first);
            }

            /** @brief Removes the element at position pos !!!!!!!! */
            void erase (iterator pos)
            {
                if (this->_tree.rb_delete(pos.base()))
                    this->_size--;
            }

            size_type erase(const Key &key)
            {
                iterator it = this->find(key);
                if (it != this->end())
                {
                    this->errase(it);
                    return 1;
                }
                return 0;
            }

            /** erases the elements in the range first to last (last not included)*/
            void erase(iterator first, iterator last)
            {
                while (first != last)
                {
                    this->erase(first);
                    first++;
                }
            }

            /** @brief exchange the content of the maps*/
            void swap( map& other)
            {
                size_type tmp = this->_size;
                this->_size = other._size;
                other._size = tmp;
                this->_tree.rb_swap(other._tree);
            }

            /************ LOOCKUP ************/

            /** @brief return the number of elements in the map having the same 
             * key value as key (either 1 or 0 since duplicated keys are not allowed)
            */
            size_type count(const Key &key)
            {
                iterator it = this->find(key);
                if (it != this->end())
                    return 1;
                return 0;
            }

            /** @brief finds an alement with equivalent key value
             * if no element found end() iterator is returned */
            iterator find(const Key &key)
            {
                value_type val = ft::make_pair(key, mapped_type());
                return iterator(this->_tree.rb_search(val), &_tree);
            }

            const_iterator find(const Key &key) const
            {
                value_type val = ft::make_pair(key, mapped_type());
                return const_iterator(_tree.rb_search(val), &this->_tree);
            }

            /** @brief returns an iterator to the first element that is smaller than key */
            iterator lower_bound( const Key &key)
            {
                value_type val = ft::make_pair(key, mapped_type());
                typename tree_val::node_ptr node = this->_tree.lower_bound(val);
                return (iterator(node, &this->_tree));
            }

            const_iterator lower_bound( const Key &key) const
            {
                value_type val = ft::make_pair(key, mapped_type());
                typename tree_val::node_ptr node = this->_tree.lower_bound(val);
                return (const_iterator(node, &this->_tree));
            }

            /** @brief returns an iterator to the first element that is greater than key */
            iterator upper_bound( const Key &key)
            {
                value_type val = ft::make_pair(key, mapped_type());
                typename tree_val::node_ptr node = this->_tree.upper_bound(val);
                return (iterator(node, &this->_tree));
            }

            const_iterator upper_bound( const Key &key) const 
            {
                value_type val = ft::make_pair(key, mapped_type());
                typename tree_val::node_ptr node = this->_tree.upper_bound(val);
                return (const_iterator(node, &this->_tree));
            }


            /** @brief returns the range between which the key is contained
             * range being from lower_bound to upper_bound
            */
            ft::pair<iterator, iterator> equal_range(const Key &key)
            {
                return ft::make_pair(lower_bound(key), upper_bound(key));
            }

            ft::pair<const_iterator, const_iterator> equal_range(const Key &key) const 
            {
                return ft::make_pair(lower_bound(key), upper_bound(key));
            }
            
            /** @brief returns the object that compares keys*/
            key_compare key_comp() const { return this->_comp;}

            value_compare value_comp() const { return value_compare(this->_comp);}
    };

    /***************** OPERTOR OVERLOAD *******************/
    /** @brief compares two maps: checks if they have the same number of elements and if each one of them are equal */
    template<class Key, class T, class Compare, class Alloc>
    bool operator==(const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs)
    {
        if (lhs._size != rhs._size)
            return false;
        return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
    }

    template<class Key, class T, class Compare, class Alloc>
    bool operator!=(const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs)
    {
        return !(lhs == rhs);
    }

    /** @brief Compares the contents of lhs and rhs lexicographically */
    template<class Key, class T, class Compare, class Alloc>
    bool operator<(const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs)
    {
        ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
    }

    template<class Key, class T, class Compare, class Alloc>
    bool operator<=(const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs)
    {
        return !(rhs < lhs);
    }

    template<class Key, class T, class Compare, class Alloc>
    bool operator>(const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs)
    {
        return (rhs < lhs);
    }

    template<class Key, class T, class Compare, class Alloc>
    bool operator>=(const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs)
    {
        return !(lhs < rhs);
    }

    /** @brief swaps the content pf lhs and rhs */
    template<class Key, class T, class Compare, class Alloc>
    void swap(const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs)
    {
        map<Key, T> tmp(lhs);
        lhs.swap(rhs);
        rhs.swap(tmp);
    }
}

#endif