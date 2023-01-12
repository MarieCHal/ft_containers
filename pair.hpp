#ifndef FT_PAIR_HPP
#define FT_PAIR_HPP

#include <iostream>

namespace ft
{
    /** @brief struct that enable two objects to be 
     * stocked in one, T1 and T2 being the types of the 
     * two elements */
    template <class T1, class T2>
    struct pair 
    {
        public:

            /** first and seccond template arguments */
            typedef T1      first_type;
            typedef T2      second_type;
            
            /** member variables: the first and second 
             * value in the pair */
            T1  first;
            T2  second;

            /** @brief construct an empty pair object */
            pair() : first(), second() {} 

            /** @brief a pair object with its value init
             * with the ones passed in argument 
             * */
            pair (const first_type& a, const second_type& b) : first(a), second(b) {}

            /** @brief construct a pair object by copy , U and V
             * being the types of the two element stocked in the src
            */
            template< class U, class V>
            pair (const pair<U, V> & src) : first(src.first), second(src.second) {}

            pair &operator=(const pair &src)
            {
                if (src != *this)
                    this->first = src.first;
                    this->second = src.second;
                return *this;
            }
    };

    //========== NON MEMBER FUNCTOINS ===============
    
    /** @brief creates a pair and returns it */
    template <class T1, class T2>
    pair<T1, T2> make_pair (T1 x, T2 y) {return pair<T1, T2>(x, y);};

    //  --- comparasion between two pair objects ---
    template <class T1, class T2>
    bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { return lhs.first==rhs.first && lhs.second==rhs.second; }

    template <class T1, class T2>
    bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { return !(lhs==rhs); }


    template <class T1, class T2>
    bool operator< (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second); }

    template <class T1, class T2>
    bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { return !(rhs<lhs); }

    template <class T1, class T2>
    bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { return rhs<lhs; }

    template <class T1, class T2>
    bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { return !(lhs<rhs); }
}

#endif