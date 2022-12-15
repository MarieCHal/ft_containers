#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP
#include "iterator_traits.hpp"
/**
 * src: https://en.cppreference.com/w/cpp/iterator/reverse_iterator
 * reverse_iterator reverses the direction of a given iterator
 * moves from the end to the begining
 * The + and - operations hwv to be inversed 
 * post incrementation operator: the operation is done before incrementing or decrementing
 * question:
 *  - why -n and -1 in [] operator? --> what is the relative location?
 * */

namespace ft
{
    template <class Iter>
    class reverse_iterator
    {
        /** MEMBER TYPES */
        public:
            typedef typename iterator_traits<Iter>::iterator_category   iterator_category;
            typedef typename iterator_traits<Iter>::value_type          value_type;
            typedef typename iterator_traits<Iter>::difference_type     difference_type;
            typedef typename iterator_traits<Iter>::pointer             pointer;
            typedef typename iterator_traits<Iter>::reference           reference;

        private:
            Iter    _it;
        
        public:
            reverse_iterator() {}

            explicit    reverse_iterator(const iterator_type &it) : _it(it) {}

            template <class Iter>
            reverse_iterator(const reverse_iterator<Iter>& rev_it) : _it(rev_it.base()) {} 

            virtual ~reverse_iterator() {}

            template <class Iter>
            reverse_iterator& operator=( const reverse_iterator<Iter>& other)
            {
                _it = other.base();
                return *this;
            }

            /** @brief: accesses the underlying iterator and returns it */
            const iterator_type base() const {return _it};

            /** @brief: access the pointed-to element */
            reference operator*() const 
            { 
                Iter tmp_it(_it)
                return *(--tmp_it);
            }
            /** @brief: access the pointed-to element */
            pointer operator->() const {return &(this->operator*())};

            /** @brief: access the element by index*/
            reference operator[](difference_type n) const {return this->_it[-n -1]};

            /** pre-incrementation operator */
            reverse_iterator& operator++()
            {
                _it--;
                return *this;
            }

            /** pre-decrementation operator */
            reverse_iterator& operator--()
            {
                _it++;
                return *this;
            }

            /** post-incrementation operator */
            reverse_iterator operator++( int )
            {
                reverse_iterator  tmp = *this;
                (this->_it--);
                return tmp;
            }

            /** post-decrementation operator */
            reverse_iterator operator--( int )
            {
                reverse_iterator tmp = *this;
                (this->_it++);
                return tmp;
            }
            
             
            reverse_iterator operator+( difference_type n ) const
            {
                reverse_iterator tmp = *this;
                tmp -= n;
                return tmp;
            }

            reverse_iterator operator-( difference_type n ) const
            {
                reverse_iterator tmp = *this;
                tmp += n;
                return *this;
            }

            reverse_iterator& operator+=( difference_type n )
            {
                this->_it -= n;
                return (*this);
            }

            reverse_iterator& operator-=( difference_type n )
            {
                this->_it += n;
                return (*this);
            }
    };
}

//================= NON MEMBER FUNCTIONS =====================

#endif