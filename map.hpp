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
                //typedef reverse_iterator<const_iterator>     const_reverse_iterator;
        
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
                
                /*************** ELEMENT ACCESS ***************/
                /** @brief take a key as argument and returns the corresponding value stored if 
                 * found in the map, else it throws an out of range exception 
                */
                mapped_type& at( const key_type &key)
                {
                    value_type data = this->_tree(key);
                    if ( data == NULL)
                        throw std::out_of_range(" Key not found in map");
                    else
                        return data.second;
                }

                /** @brief returns a reference to the stored value by searching the key, if not found
                 * insert a new key value pair and return the newly inserted value
                */
                mapped_type& operator[](const key_type& key)
                {
                    value_type data = this->_tree(key);
                    if ( data == NULL)
                    {
                        data = ft::make_pair<key, NULL>;
                        this->_tree->rb_insert(data);
                    }
                    return data->second;
                }

                /**************** ITERATORS ****************/

                /** @brief an iterator to the smallest key stored in the map, which is considered
                 * as the begining of the map */
                iterator begin() { return this->_tree->rb_min();}
                const_iterator begin() const { return this->_tree->rb_min();}

                iterator end() { return this->_tree->rb_max();}
                const_iterator end() const { return this->_tree->rb_max();}

                reverse_iterator rbegin() {return (this->_tree->rb_max() - 1);}
                //const_reverse_iterator rbegin() const {return (this->_tree->rb_max() - 1);}

                reverse_iterator rend() { return (this->_tree->rb_min() - 1);}
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
                    this->_tree->clear();
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
                    return this->_tree->rb_insert(value);
                }

                /** @brief iterator pos specfies from where the searching operation for insertion is to
                 * be done to accelerate the process
                */
                iterator insert(iterator pos, const value_type &value) {}

                /** @brief inserts in the map the elements contained between first and last
                 * has undefined behavior if elements in the range have keys that compare 
                 * equivalent */
                template<class InputIt>
                void insert( InputIt first, InputIt last)
                {
                    for (;first != last ; first++)
                        this->_tree->rb_insert(*first);
                }

                /** @brief Removes the element at position pos !!!!!!!! */
                /*iterator erase(iterator pos)
                {
                    this->_tree->rb_delete(*pos);
                }

                iterator erase( iterator first, iterator last)
                {

                }*/

                /** @brief exchange the content of the maps*/
                void swap( map& other)
                {
                    this->_tree->rb_swap(other._tree);
                    this->_size = other._size;
                }

                /************ LOOCKUP ************/

                /** @brief return the number of elements in the map having the same 
                 * key value as key (either 1 or 0 since duplicated keys are not allowed)
                */
                size_type count(const Key &key)
                {
                    iterator begin = this->begin();
                    iterator end = this->end();
                    for (; begin != end; begin++)
                    {
                        if (*(begin).first == key)
                            return 1;
                    }
                    return 0;
                }

                /** @brief finds an alement with equivalent key value
                 * if no element found end() iterator is returned */
                iterator find(const Key &key)
                {
                    iterator begin = this->begin();
                    iterator end = this->end();
                    for (; begin != end; begin++)
                    {
                        if (*(begin).first == key)
                            return begin;
                    }
                    return begin;
                }

                

    };
}

#endif