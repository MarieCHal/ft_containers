#ifndef UNABLE_IF_HPP
#define UNABLE_IF_HPP

/** 
 * enable_if helps to diferenciate function that could be interpreted similarly
 * is_integral checks if the argument is a an integral (char, float, int etc.)
**/

namespace ft
{
    /** @brief template struct for enable_if
     * if the result of is_integral is false than this struct will be used 
     * the type T is not existant hence the function will be ignored **/
    template<bool B, class T = void>
    struct enable_if {};

    /** @brief of initial struct enable_if 
     * if the result of is_integral is true then this struct will be used
     * T type exists and hence the function will be used **/
    template<class T>
    struct enable_if<true, T> 
    {
        typedef T   type;
    };

    /** @brief if the parameter T is intergral
     * if it is the is_itegral value will be true **/
    template<bool is_integral, class T>
    struct stock_is_integral
    {
        typedef T type;
        static const bool value = is_integral;
    };

    /** 
     * 1. default is_integral_type struct (set to false)
     * 2. define the struct is_integral which publicly enherits from is_integral_type
     *      is_integral_type is a specialisation template struct of is_integral
     * 3. if the parmeter 'T' corresponds to one of the specilisation of is_integral_type
     *      it will overwrite the initial is_integral_type enherited by is_integral
     *      and set its value (which says if 'T' is an integral) to true
     * **/
    template <typename> struct is_integral_type : public stock_is_integral<false, bool> {};
    template <typename T> struct is_integral : public is_integral_type<T> {};
    template < > struct is_integral_type<char> : public stock_is_integral<true, char> {};
    template < > struct is_integral_type<signed char> : public stock_is_integral<true, char> {};
    template < > struct is_integral_type<unsigned char> : public stock_is_integral<true, char> {};
    template < > struct is_integral_type<int> : public stock_is_integral<true, char> {};
    template < > struct is_integral_type<long int> : public stock_is_integral<true, char> {};
    template < > struct is_integral_type<unsigned int> : public stock_is_integral<true, char> {};
    template < > struct is_integral_type<unsigned long int> : public stock_is_integral<true, char> {};
    template < > struct is_integral_type<long long int> : public stock_is_integral<true, char> {};
    template < > struct is_integral_type<unsigned long long int> : public stock_is_integral<true, char> {};
    template < > struct is_integral_type<short int> : public stock_is_integral<true, char> {};
    template < > struct is_integral_type<unsigned short int> : public stock_is_integral<true, char> {};
    template < > struct is_integral_type<bool> : public stock_is_integral<true, char> {};
}

#endif