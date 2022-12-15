#ifndef ITERATOR_TRAITS
# define ITERATOR_TRAITS

/** NOTES:
 * - only bidirectional and random access iterator tags are needed??
 * **/

/**
 * see src: https://en.cppreference.com/w/cpp/iterator/iterator_traits
 * @brief iterator tags are used to know the properties of the iterator
 * @brief iterator_traits provides uniform interface, makes it possible to 
 * implement algorithms only in terms of iterators
 * **/

/** ITARATOR TRAITS
 * itrator category: the type of the iterator
 * value_type: the type of value it is pointing to 
 * difference type:
 * pointer:
 * reference: 
 * */

namespace ft
{
    struct input_iterator_tag {};
    struct output_iterator_tag {};
    struct forward_iterator_tag : public input_iterator_tag {};
    struct bidirectional_iterator_tag : public forward_iterator_tag {};
    struct random_access_iterator_tag : public bidirectional_iterator_tag {};

    template <class Iter>
    struct iterator_traits {
        typedef typename Iter::iterator_category iterator_category;
        typedef typename Iter::value_type        value_type;
        typedef typename Iter::difference_type   difference_type;
        typedef typename Iter::pointer           pointer;
        typedef typename Iter::reference         reference;
    };

    template <class T>
    struct iterator_traits<T*> {
        typedef random_access_iterator_tag iterator_category;
        typedef T                          value_type;
        typedef ptrdiff_t                  difference_type;
        typedef T*                         pointer;
        typedef T&                         reference;
    };

    template <class T>
    struct iterator_traits<T* const> {
        typedef random_access_iterator_tag iterator_category;
        typedef const T                          value_type;
        typedef ptrdiff_t                  difference_type;
        typedef const T*                         pointer;
        typedef const T&                         reference;
    };
}

#endif