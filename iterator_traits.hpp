#ifndef FT_ITERATOR_TRAITS
# define FT_ITERATOR_TRAITS

/** NOTES:
 * - only bidirectional and random access iterator tags are needed??
 * **/

/** SRCS: https://en.cppreference.com/w/cpp/iterator/iterator_traits
 * */


namespace ft
{
    /**
     * @brief iterator tags are used to know the properties of the iterator
     * **/
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

    /** @brief iterator_traits provides uniform interface, makes it possible to 
     * implement algorithms only in terms of iterators
     * */
    template <class T>
    struct iterator_traits<T*> {
        typedef random_access_iterator_tag iterator_category;
        typedef T                          value_type; /** iterator value_type */
        typedef ptrdiff_t                  difference_type; /** used to store the number of 'hops between two itreators (can be negative) **/
        typedef T*                         pointer; /** pointer on iterator of type T */
        typedef T&                         reference; /** reference on iterator of type T */
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