
#include "vector.hpp"
#include <vector>

template < class T>
void std_print(std::vector<T> vect)
{
    size_t pos;
    pos = 0;
    std::cout << "std_vector: ";
    while (pos < vect.size())
    {
        std::cout << vect.at(pos);
        pos++;
    }
    std::cout << " capcity: " << vect.capacity() << " size: " << vect.size();
    std::cout << std::endl;
}

// TO DO :
// fix capcity * 2
// iterator traits
// should insert just insert or move all the other values? (TEST 4)


int main(void)
{
    ft::vector<char>ft_vector (5, 'a');
    std::vector<char>std_vector (5, 'a');


    std::cout << "---- PART 1: MEMBER FUNCTION ---- " << std::endl;
    std::cout << "---- TEST 1: constructor ---- " << std::endl;
    std::cout << "---- TEST 2: destructor ---- " << std::endl;
    std::cout << "---- TEST 3: operator= ---- " << std::endl;
    std::cout << "---- TEST 4: assign  ---- " << std::endl;
    std::cout << "---- TEST 5: get_allocator ---- " << std::endl;

    std::cout << "---- PART 2: ELEMENT ACCESS ---- " << std::endl;
    std::cout << "---- TEST 1: at ---- " << std::endl;
    std::cout << "---- TEST 2: operator[] ---- " << std::endl;
    std::cout << "---- TEST 3: front ---- " << std::endl;
    std::cout << "---- TEST 4: back ---- " << std::endl;
    std::cout << "---- TEST 5: data ---- " << std::endl;

    std::cout << "---- PART 3: ITERATORS ---- " << std::endl;
    std::cout << "---- TEST 1: begin ---- " << std::endl;
    std::cout << "---- TEST 2: end ---- " << std::endl;
    std::cout << "---- TEST 3: rbegin ---- " << std::endl;
    std::cout << "---- TEST 4: rend ---- " << std::endl;


    std::cout << "---- PART 4: CAPACITY ---- " << std::endl;
    std::cout << "---- TEST 1: empty ---- " << std::endl;
    std::cout << "---- TEST 2: size ---- " << std::endl;
    std::cout << "---- TEST 3: max_size ---- " << std::endl;
    std::cout << "---- TEST 4: reserve ---- " << std::endl;
    std::cout << "---- TEST 5: capacity ---- " << std::endl;

    std::cout << "---- PART 5: MODIFIERS ---- " << std::endl;
    std::cout << "---- TEST 1: clear ---- " << std::endl;
    std::cout << "---- TEST 2: insert ---- " << std::endl;
    std::cout << "---- TEST 3: emplace ---- " << std::endl;
    std::cout << "---- TEST 4: erase ---- " << std::endl;
    std::cout << "---- TEST 5: push_back---- " << std::endl;
    std::cout << "---- TEST 6: pop_back---- " << std::endl;
    std::cout << "---- TEST 7: resize ---- " << std::endl;
    std::cout << "---- TEST 8: swap ---- " << std::endl;


    std::cout << "---- PART 6: NON_MEMBER FUNCTIONS ---- " << std::endl;
    std::cout << "---- TEST 1: operator== ---- " << std::endl;
    std::cout << "---- TEST 2: operator!= ---- " << std::endl;
    std::cout << "---- TEST 3: operator< ---- " << std::endl;
    std::cout << "---- TEST 4: operator<= ---- " << std::endl;
    std::cout << "---- TEST 5: oprator> ---- " << std::endl;
    std::cout << "---- TEST 5: oprator>= ---- " << std::endl;
    std::cout << "---- TEST 6: std::swap ---- " << std::endl;

    ft_vector.print_vect();
    std_print(std_vector);
    
}