#ifndef FT_REVERSE_ITERATOR_HPP
# define FT_REVERSE_ITERATOR_HPP
#include "iterator_traits.hpp"
/**
 * SRC: https://en.cppreference.com/w/cpp/iterator/reverse_iterator
 * reverse_iterator reverses the direction of a given iterator
 * moves from the end to the begining
 * The + and - operations have to be inversed 
 * post incrementation operator: the operation is done before incrementing or decrementing
 * question:
 *  - why -n and -1 in [] operator? --> what is the relative location?
 * */

namespace ft
{
    template <class InputIter> 
    class reverse_iterator
    {
        /** MEMBER TYPES */
        public:
            typedef InputIter Iter;
            typedef const InputIter constIter;
            typedef typename iterator_traits<Iter>::iterator_category   iterator_category;
            typedef typename iterator_traits<Iter>::value_type          value_type;
            typedef typename iterator_traits<Iter>::difference_type     difference_type;
            typedef typename iterator_traits<Iter>::pointer             pointer;
            typedef typename iterator_traits<Iter>::reference           reference;

        private:
            Iter    _it;
        
        public:
            reverse_iterator() {}

            explicit    reverse_iterator(const Iter &it) : _it(it) {}

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
            constIter &base() const {return _it;};

            /** @brief: access the pointed-to element */
            reference operator*() const 
            { 
                Iter tmp_it(_it);
                return *(--tmp_it);
            }

            reference operator*()
            { 
                Iter tmp_it(_it);
                return *(--tmp_it);
            }

            /** @brief: access the pointed-to element */
            pointer operator->() const {return &(this->operator*());};

            /** @brief: access the element by index*/
            reference operator[](difference_type n) const {return this->_it[-n -1];};

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

    //================= NON MEMBER FUNCTIONS =====================
    template< class Iterator1, class Iterator2 >
    bool operator==(const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2> &rhs)
    {
        return lhs.base() == rhs.base();
    }

    template <class InputIter>
    bool operator==(const reverse_iterator<InputIter> &lhs, const reverse_iterator<InputIter> &rhs)
    {
        return lhs.base() == rhs.base();
    }

    template< class Iterator1, class Iterator2 >
    bool operator!=(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs )
    {
        return lhs.base() != rhs.base();
    }

    template <class InputIter>
    bool operator!=(const reverse_iterator<InputIter> &lhs, const reverse_iterator<InputIter> &rhs)
    {
        return lhs.base() != rhs.base();
    }

    template< class Iterator1, class Iterator2 >
    bool operator<( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs )
    {
        return lhs.base() < rhs.base();
    }

    template <class InputIter>
    bool operator<(const reverse_iterator<InputIter> &lhs, const reverse_iterator<InputIter> &rhs)
    {
        return lhs.base() < rhs.base();
    }
    
    template< class Iterator1, class Iterator2 >
    bool operator<=( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs )
    {
        return lhs.base() <= rhs.base();
    }

    template <class InputIter>
    bool operator<=(const reverse_iterator<InputIter> &lhs, const reverse_iterator<InputIter> &rhs)
    {
        return lhs.base() <= rhs.base();
    }
    
    template< class Iterator1, class Iterator2 >
    bool operator>( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs )
    {
        return lhs.base() > rhs.base();
    }

    template <class InputIter>
    bool operator>(const reverse_iterator<InputIter> &lhs, const reverse_iterator<InputIter> &rhs)
    {
        return lhs.base() > rhs.base();
    }
    
    template< class Iterator1, class Iterator2 >
    bool operator>=( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs )
    {
        return lhs.base() >= rhs.base();
    }

    template <class InputIter>
    bool operator>=(const reverse_iterator<InputIter> &lhs, const reverse_iterator<InputIter> &rhs)
    {
        return lhs.base() >= rhs.base();
    }
}



#endif