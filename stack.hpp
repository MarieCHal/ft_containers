#ifndef STACK_HPP
#define STACK_HPP

#include "vector.hpp"

/**  @brief it is a container that uses another container as underlying storage
 * data is stored in a linear fashioin meaning the last added element will be 
 * the first retrieved
*/

namespace ft
{
    template<class T, class Container = ft::vector<T> >
    class stack
    {
        public:
            typedef Container               container_type;
            typedef typename Container::value_type   value_type;
            typedef typename Container::size_type     size_type;
            typedef typename Container::reference        reference;
            typedef typename Container::const_reference   const_reference;

        protected:
            container_type _cont; // underlying container (in this case vector)

        public:
        /** MEMBER FUNCTIONS */
        /** @brief default constructor */
        explicit stack( const Container& cont = Container() ) : _cont(cont) {}

        /** @brief copy constructor */
        stack( const stack& other ) {
            this->_cont = other._cont;
        }

        /** @brief destructor */
        ~stack() {}

        stack& operator=( const stack& other ) {
            this->_cont = other._cont;
        }

        /********* ELEMENT ACCESS *************/
        /** @brief return a ref to the last element */
        reference top() {
            return _cont.back();
        }

        const_reference top() const {
            return _cont.back();
        }

        /********** CAPACITY *******************/
        bool empty() const {
            return this->_cont.empty();
        }

        size_type size() const {
            return this->_cont.size();
        }

        /** @brief adds value to underlying container*/
        void push( const value_type& value ) {
            this->_cont.push_back(value);
        }

        /** @brief removes the top element */
        void pop() {
            this->_cont.pop_back();
        }

        /** @brief allows non memeber operator overload to access protected underlying container*/
        template< class T2, class Cont >
        friend bool operator==(const stack<T2, Cont>& lhs, const stack<T2, Cont>& rhs);
        template< class T2, class Cont >
        friend bool operator!=(const stack<T2, Cont>& lhs, const stack<T2, Cont>& rhs);
        template< class T2, class Cont >
        friend bool operator<(const stack<T2, Cont>& lhs, const stack<T2, Cont>& rhs);
        template< class T2, class Cont >
        friend bool operator<=(const stack<T2, Cont>& lhs, const stack<T2, Cont>& rhs);
        template< class T2, class Cont >
        friend bool operator>(const stack<T2, Cont>& lhs, const stack<T2, Cont>& rhs);
        template< class T2, class Cont >
        friend bool operator>=(const stack<T2, Cont>& lhs, const stack<T2, Cont>& rhs);

    };

    template< class T, class Container >
    bool operator==( const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs )
    {
        return lhs._cont == rhs._cont;
    }

    template< class T, class Container >
    bool operator!=( const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs )
    {
        return lhs._cont != rhs._cont;
    }

    template< class T, class Container >
    bool operator<( const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs )
    {
        return lhs._cont < rhs._cont;
    }

    template< class T, class Container >
    bool operator<=( const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs )
    {
        return lhs._cont <= rhs._cont;
    }

    template< class T, class Container >
    bool operator>( const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs )
    {
        return lhs._cont > rhs._cont;
    }

    template< class T, class Container >
    bool operator>=( const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs )
    {
        return lhs._cont >= rhs._cont;
    }
}

#endif