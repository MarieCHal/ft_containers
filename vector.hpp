#ifndef TEST_HPP
# define TEST_HPP

// INCLUDES ====================================================
#include <memory>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstddef>
#include "equal.hpp"

// 1. constructors
// 2. Functions that do not require iterator
// 3. Create the Iterator class
// 4. Implement functions with iterators
// 5. Operators overloading

//iterator traits
//random iterators
//data
//================ QUESTIONSS =========================
//-->check dif between NULL and u_nullptr
//--> when do we need to 'this' inside a member function to access a private attribute
//--> at: does the number of element in a vector starts at 0 or 1
//--> capcity * 2 ??
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

            //---------> the iterators have to be coded
            //Arandom access iterator to value_type
            // that can read or modify an element stored
            typedef pointer                 iterator;
            //typedef typename ft::random_access_iterator<const value_type> const_iterator;
            //used to iterate through the vector in reverse
            //can be used to modify a value
            //typedef typename ft::reverse_iterator<iterator> reverse_iterator;
            //typedef typename ft::reverse_iterator<iterator> const_reverse_iterator;
        
        private:
        //maybe add a pointer to the start and to the end of the vector
            allocator_type  _allocator; //allocates memory
            pointer         _start; //pointer on array of element stocked (begining)
            pointer         _end; //pointer on last element of array
            size_type       _capacity; //max size of the array
        //can add a function that check if an element is in a range otherwise thhrow an exception


        //vector() {};
        public:

        //constructor
        // Default constructor does not allocate memory for the vector
        // set the capacity and size to zero: vector<>;
        explicit vector(const allocator_type& alloc = allocator_type()) : 
                            _allocator(alloc),
                            _start(NULL),
                            _end(NULL),
                            _capacity(0) {}


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
        vector (const vector& x);

        // destructor
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


        // --- MEMBER FUNCTIONS ---
        // opertaor=

        // assign
        void assign (size_type n, const value_type& val)
        {
            clear();
            insert(this->begin(), n, val);
        }
        // get_allocator --> returns the allocator associated with the container
        allocator_type get_allocator() const {return this->_allocator;}
        //allocator_type get_allocator() const noexcept;


        // --- ELEMENT ACCESS ---
        // at
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
        // operator[]
        // front
        reference front() {return (*(this->_start)); }
        // back
        reference back() {return (*(this->_end -1)); }
        // data --> returns a pointer to the underlying array
        pointer data() {return (this->_start);}



        // --- ITERATORS ---
        // begin
        // end
        // rbegin
        // rend

        // --- CAPACITY ---
        // empty
        bool   empty() const    {return this->_start == this->_end;}
        // size
        size_type size() const          {return this->_end - this->_start;}
        // max_size
        size_type max_size() const      {return _allocator.max_size();}
        // reserve
        void    reserve(size_type new_cap)
        {
            if (new_cap > max_size())
                std::cout << "Error max size" << std::endl;
                //throw std::length_error("Length error: vector::reserve");
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
        // capacity
        size_t capacity() const {return this->_capacity;}


        // --- MODIFIERS ---
        // clear
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
        iterator insert (iterator pos, const value_type& val)
        {
            insert(pos, 1, val);
            return pos;
        }
    
        void    insert (iterator pos, size_type n, const value_type& val)
        {
            if (n > max_size() || n + size() > max_size())
                std::cout << "Error" << std::endl;
                //throw std::length_error("Length error: vector::insert");
            size_type start = std::distance(begin(), pos);
            size_type end = size();
            resize(size() + n);
            ft::copy_backward(begin() + start, begin() + end, begin() + start + n);
            ft::fill(begin() + start, begin() + start + n, val);
            this->_capacity = n;
        }
        // emplace
        // erase
        iterator erase(iterator pos)
        {
            if (pos == end())
                return (end());
            else
            {
                while (pos != this->end())
                {
                    pos = pos + 1;
                }
                this->_allocator.destroy(this->end() - 1 );
                this->_end--;
            }
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
                //why???
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


//===============================


        //remove the last add element of the vector
        //reduces the size of the vector, if empty has undefined behaviour
        //need an iterator

        //exceptions: std::out of range


        //insert element val at position pos.
        //can increase the size of the container
        //realocates memory for all elements after pos
        // returns an iterator to the new element val
        //iterator insert(iterator pos, const value_type& val);

        //same as the precedent but add n number of time the value val
        //starting at position pos
        //iterator insert(iterator pos, size_type n, const value_type& val);


        //ITERATORS
        iterator begin()                        {return iterator(this->_start);}
        //const_iterator begin() const            {return const_iterator(this->_start);}
        iterator end()                          {return iterator(this->_end);}
        /*const_iterator end() const              {return const_iterator(this->_end);}
        reverse_iterator rbegin()               {return reverse_iterator(this->_end);}
        const_reverse_iterator rbegin() const   {return const_reverse_iterator(this->_end);}
        reverse_iterator rend()                 {return reverse_iterator(this->_start);}
        const_reverse_iterator rend() const     {return const_reverse_iterator(this->_start);}*/
        //check later
        /*template <class InputIterator>
					vector (InputIterator first, InputIterator last,
							const allocator_type& alloc = allocator_type(),
							typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = u_nullptr);*/

        //copy constructor

        //destructor
        //destroy all elements of the container and deallocate the memory

        /*o
        -- perator overloading
        -- destroy the previous stored elements
        -- returns the vector*/
        vector &operator=(const vector& x);



        /*
        .. Returns an iterator pointing to the first element of the container
        .. If empty first = last
        .. type iterator (random acess iterator on value_type reference)
        */
        //iterator begin() { return (_start); };
        
        //same as above but random access iterator on const value_type reference)
        //const_iterator begin() const { return (_start); }


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