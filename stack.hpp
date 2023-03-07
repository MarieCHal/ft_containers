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
        typedef Container::value_type   value_type;
        typedef Container::size_type     size_type;
        typedef Container::reference        reference;
        typedef Container::const_refernce   const_reference;

        private:
            container_type _cont; // underlying container (in this case vector)

        /** MEMBER FUNCTIONS */
        stack() {
            _cont();
        }
    };

}

#endif