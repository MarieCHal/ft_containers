#ifndef FT_VECTOR_HPP
# define FT_VECTOR_HPP

// INCLUDES ====================================================
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

// 1. constructors
// 2. Functions that do not require iterator
// 3. Create the Iterator class
// 4. Implement functions with iterators
// 5. Operators overloading

namespace ft
{
    template< class T, class Allocator = std::allocator<T> >
    class vector
    {
        public: //member types

            //first template param
            typedef T  value_type;

            //the second template param
            typedef Allocator allocator_type;

            //usualy same as size_t
            typedef std::size_t size_type;

            //A type provides a reference to an element stored in vector.
            //Default allocator is a ref to value_type;
            typedef typename allocator_type::reference reference;
            typedef typename allocator_type::const_reference const_reference;

            // type that gives a pointer to an element stored
            // a type pointer can be used to modify the value of an element 
            // Default pointer is a pointer to value_type
            typedef typename allocator_type::pointer pointer;
            typedef typename allocator_type::const_pointer const_pointer;

            //Arandom access iterator to value_type
            // that can read or modify an element stored
            typedef pointer                 iterator;
            typedef const_pointer           const_iterator;

            //used to iterate through the vector in reverse
            //can be used to modify a value
            typedef typename ft::reverse_iterator<iterator> reverse_iterator;
            typedef typename ft::reverse_iterator<iterator> const_reverse_iterator;
        
        private:
            allocator_type  _allocator; //allocates memory
            iterator         _start; //pointer on array of element stocked (begining)
            iterator         _end; //pointer on last element of array
            size_type       _capacity; //max size of the array

        public:

        //constructor
        /** @brief default constructor, construct an empty container with default
         * constructed allocator */
        explicit vector(const allocator_type& alloc = allocator_type()) : 
                            _allocator(alloc),
                            _start(NULL),
                            _end(NULL),
                            _capacity(0) {}

        /** @brief construct a container with n copies of val */
        explicit vector(size_type n, const value_type &val = value_type(), 
                                const allocator_type &alloc = allocator_type()) :
                            _allocator(alloc),
                            _start(NULL),
                            _end(NULL),
                            _capacity(n) 
            {
                this->_start = this->_allocator.allocate(n);
                this->_end = this->_start;
                assign(n, val);
            }
        
        /** @brief construct a container with content of the range [first, last] */
        template <class InputIterator>
        vector (typename ft::enable_if<!ft::is_integral<InputIterator>::value, 
            InputIterator>::type first, InputIterator last, const allocator_type 
            &alloc = allocator_type() ) : _allocator(alloc), _start(), _end(), _capacity()
        {
            this->assign(first, last);
        }

        /** @brief copy constructor */
        vector (const vector& other) : _allocator(other._allocator), _start(NULL), _end(NULL), _capacity(0) 
        {
            this->_capacity = other._capacity;
            this->_start = _allocator.allocate(this->_capacity);
            this->_end = this->_begin;
            this->assign(other.begin(), other.end());
        }

        /** destructor @brief deallocate memory to prevent memory leaks */
        ~vector() 
        {
            clear();
            this->_allocator.deallocate(this->_start, this->_capacity);
        }

        // justt usefull to test
        void print_vect()
        {
            size_t pos = 0;
            std::cout << "ft_vector : ";
            while (pos < size())
            {
                std::cout << at(pos);
                pos++;
            }
            std::cout << " capcity: " << this->capacity() << " size: " << this->size();
            std::cout << std::endl;
        }


        // ========================= MEMBER FUNCTIONS =========================

        /** opertaor= @brief Replaces the contents with a copy of the contents of other. */
        vector &operator=(const vector &other)
        {
            this->assign(other.begin(), other.end());
            return *this;
        }

        //assign
        /** @brief Replaces the contents with count copies of value value */
        void assign (size_type n, const value_type& val)
        {
            clear();
            insert(this->begin(), n, val);
        }

        /** @brief replaces the content with content of range [first, last] */
        template< class InputIt >
        void assign( InputIt first, InputIt last )
        {
            clear();
            size_t dis = ft::distance(first, last);
            if (dis > _capacity)
                reserve(dis);
            iterator tmp = _start;
            while (first != last)
            {
                _start = first;
                _start++;
                first++;
            }
            _start = tmp;
        }
        
        // get_allocator
        /** @brief returns the allocator associated with the container */
        allocator_type get_allocator() const {return this->_allocator;}


        // ========================= ELEMENT ACCESS =========================

        // at
        /** @brief returns a reference of the element at position pos */
        reference at (size_type pos)
        {
            iterator it;
            size_t count;
            it = this->begin();
            count = 0;
            if (pos > this->size() || pos < this->size())
                std::out_of_range("Vector index out of range");
            while (count != pos)
            {
                it++;
                count++;
            }
            return (*it);
        }
        /** @brief returns a const reference of the element at position pos */
        const_reference at (size_type pos) const {return const_reference(at(pos));};

        // operator[]
        /** @brief return a refence to the element at position n */
        reference operator[] (size_type n) {return at(n);}
        const_reference operator[] (size_type n) const {return const_reference(at(n));}

        // front
        /** @brief return a reference to the first element of the container */
        reference front() {return (*(this->_start));}
        const_reference front() const {return const_reference(*(this->_start));}
    
        // back
        /** @brief return a reference to the last element of the container */
        reference back() {return (*(this->_end -1)); }
        const_reference back() const {return const_reference(*(this->_end -1));}

        /** data() 
         * @brief: returns a pointer to the underlying array */
        pointer data() {return (this->_start);}
        const_pointer data() const {return const_pointer(this->_start);}

        // ========================= ITERATORS =========================
        iterator begin()                        {return iterator(this->_start);}
        const_iterator begin() const            {return const_iterator(this->_start);}
        iterator end()                          {return iterator(this->_end);}
        const_iterator end() const              {return const_iterator(this->_end);}
        reverse_iterator rbegin()               {return reverse_iterator(this->_end);}
        const_reverse_iterator rbegin() const   {return const_reverse_iterator(this->_end);}
        reverse_iterator rend()                 {return reverse_iterator(this->_start);}
        const_reverse_iterator rend() const     {return const_reverse_iterator(this->_start);}

        // --- CAPACITY ---
        /** empty @brief checks is the container is empty */
        bool   empty() const    {return this->_start == this->_end;}

        /** size @brief returns the current number of element in the container */
        size_type size() const          {return this->_end - this->_start;}

        /** max_size @brief Returns the maximum number of elements the container is able to hold
         * according to the allocator*/
        size_type max_size() const      {return _allocator.max_size();}

        /** reserve @brief increases the capcity of the container to new_cap by allocating space*/
        void    reserve(size_type new_cap)
        {
            if (new_cap > max_size())
                throw std::length_error("Length error: ft_vector::reserve()");
            if (new_cap <= this->_capacity)
                return ;
            if (new_cap > this->_capacity)
            {
                pointer tmp = this->_allocator.allocate(new_cap);
                int i = 0;
                while (this->_start + i != this->_end)
                {
                    this->_allocator.construct(&tmp[i], *(this->_start + i));
                    i++;
                }
                clear();
                this->_allocator.deallocate(this->_start, this->_capacity);
                this->_start = tmp;
                this->_end = this->_start + i;
                this->_capacity = new_cap;
            }
        }

        /** capacity @brief returns the capcity of the container */
        size_t capacity() const {return this->_capacity;}


        // --- MODIFIERS ---

        /** clear @brief clear the data stored in the conatiner but keep the capcity */
        void    clear()
        {
            pointer ptr = this->_start;
            while (ptr != this->_end)
            {
                this->_allocator.destroy(ptr);
                ptr++;
            }
            this->_end = this->_start;
        }

        // insert
        /** @brief inserts val at position pos -1 */
        iterator insert (iterator pos, const value_type& val)
        {
            insert(pos, 1, val);
            return pos;
        }

        /** @brief inserts val n times starting at position pos -1, cpoying backwards */
        void    insert (iterator pos, size_type n, const value_type& val)
        {
            if (n > max_size() || n + size() > max_size())
                throw std::length_error("Length error: ft_vector::insert()");
            size_type start = ft::distance(begin(), pos);
            size_type end = size();
            resize(size() + n);
            ft::copy_backward(begin() + start, begin() + end, begin() + start + n);
            ft::fill(begin() + start, begin() + start + n, val);
            this->_capacity = n;
        }

        // erase
        /** @brief removes the element at position pos 
         * returns the iterator following the last removed element */
        iterator erase(iterator pos)
        {
            if (pos == end())
                return (end());
            else
            {
                while (pos != this->end())
                {
                    pos = pos + 1;
                    pos++;
                }
                this->_allocator.destroy(this->end() - 1 );
                this->_end--;
                this->_size--;
            }
        }

        iterator erase( iterator first, iterator last )
        {
            
        }

        // push_back
        void push_back(const value_type& value)
        {
            if (this->size() == 0)
                this->reserve(1);
            else if (this->size() + 1 > this->capacity())
                this->reserve(this->capacity() * 2);
            this->_allocator.construct(this->_end, value);
            this->_end++;
        }
        // pop_back
        void    pop_back()
        {
            if (size() > 0)
            {   
                this->_allocator.destroy(this->end() - 1);
                this->_end--;
            }
        }
        // resize
        void    resize (size_type n, value_type val = value_type())
        {
            if (n > max_size())
                std::cout << "Error max size\n";
            if (n < size())
            {
                pointer tmp = this->_start + n;
                while (tmp != this->_end)
                {
                    this->_allocator.destroy(tmp);
                    tmp++;
                }
                this->_end = this->_start + n;
            }
            else if (n > size())
            {
                if (n > this->_capacity)
                {   
                    if (n > this->_capacity * 2)
                        reserve(this->_capacity * 2);
                    else 
                        reserve(n);
                }
                for (size_t i = size(); i < n; i++)
                {
                    this->_allocator.construct(this->_end, val);
                    this->_end++;
                }
            }
        }
        // swap
        
        

    };
// NON MEMBER FUNCTIONS ==============
// conmpares vector containers to know if they are equal (== )
    template <class T, class Allocator>
    bool operator==(const ft::vector<T, Allocator> &vect1, const ft::vector<T, Allocator> &vect2)
    {
        if (vect1.size() != vect2.size())
            return (false);
        else 
        {
            typename ft::vector<T>::iterator it1;
            typename ft::vector<T>::iterator it2;
            it1 = vect1.begin();
            it2 = vect2.begin();
            while (it1 != vect1.end())
            {
                if (*it1 != *it2)
                    return (false);
                it1++;
                it2++;
            }
        }
        return (true);
    }

// compares vector container to see if they are not equal (!=)
    template <class T, class Allocator>
    bool operator!=(const ft::vector<T, Allocator> &vect1, const ft::vector<T, Allocator> &vect2)
    {
        return (!(vect1 == vect2));
    }

//  compares vector container to see if no1 is smaller than no2 (<)

// compares vector container to see if no1 is bigger than no2 (>)

// compares vector container to see if no1 is bigger or equal to no2 (>=)

}




#endif