
#include "vector.hpp"
#include "map.hpp"
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
    std::cout << std::endl << std::endl;
}

// TO DO :
// should insert just insert or move all the other values? (TEST 4)
//random iterators
// iteraor distance
// equal with binarypredicate? 
//tester vector

/** ================ QUESTIONS =========================
 * --> capcity * 2 ?? as in stl function
 * iterator traits : class Iter -> iterato_category? and then rdm iterator tag
 *                 : only bidirectional and random access iterator tags are needed??
 * we have to implement functions related to iterators? (ex. fill())
 * is a pointer a bidirectional iterator ? (reverse iterator need a bid. it.)
 * rev_it: virtual, explicit
 * 
 * algorithms: do me need to code the binary predicted?
 * dif template class or typename
 * inserts -> check more in details
 * map, pair struct : why iostream << operator ?
*/


int main(void)
{

    //std::cout << "==== PART 1: MEMBER FUNCTION ==== \n\n";
    //std::cout << "---- TEST 1: constructor ---- " << std::endl;
    //missing some constructors
    /*ft::vector<char>ft_vector(6);
    std::cout << ft_vector.size() << std::endl;
    ft_vector.push_back('a');
    ft_vector.push_back('b');
    ft_vector.push_back('c');
    std::cout << "ft_vector : " << ft_vector.back() << std::endl;
    std::vector<char>std_vector(6);
    std::cout << std_vector.size() << std::endl;
    std_vector.push_back('a');
    std_vector.push_back('b');
    std_vector.push_back('c');
    std::cout << "std_vector : " << std_vector.back() << std::endl;*/
    ft::vector<int> ft_vector;
    std::vector<int> std_vector;
    /*std_vector.insert(std_vector.end(), 42);
    std_print(std_vector);
    ft_vector.insert(ft_vector.end(), 42);
    ft_vector.print_vect();

    std::cout << "---- TEST 1: at ---- " << std::endl;
    std_vector.insert(std_vector.end(), 43);
    std_vector.insert(std_vector.end(), 44);
    ft_vector.insert(ft_vector.end(), 43);
    ft_vector.insert(ft_vector.end(), 44);
    std::cout << "ft_vector at 2: " << ft_vector.at(1) << std::endl;
    std::cout << "std_vector at 2: " << std_vector.at(1) << std::endl;
    //std::cout << "---- TEST 2: destructor ---- " << std::endl;
    //std::cout << "---- TEST 3: operator= ---- " << std::endl;
    std::cout << "ft_vector front: " << ft_vector.front() << std::endl;
    std::cout << "std_vector front : " << std_vector.front() << std::endl;
    std::cout << "---- TEST 4: back ---- " << std::endl;
    std::cout << "ft_vector back: " << ft_vector.back() << std::endl;
    std::cout << "std_vector back: " << std_vector.back() << std::endl;
    std::cout << "---- TEST 4: assign  ---- " << std::endl;
    ft_vector.assign(5, 3);
    std_vector.assign(5, 3);
    ft_vector.print_vect();
    std_print(std_vector);*/

    std::cout << "INSERT TEST!!!!!!!!!!!" << std::endl;
    for (unsigned long int i = 0; i < ft_vector.size(); ++i)
		ft_vector[i] = (ft_vector.size() - i) * 3;
    for (unsigned long int i = 0; i < ft_vector.size(); ++i)
		ft_vector[i] = (ft_vector.size() - i) * 3;
    ft_vector.print_vect();
    std_print(std_vector);


	ft_vector.insert(ft_vector.end(), 42);
	ft_vector.insert(ft_vector.begin(), 2, 21);
    std_vector.insert(std_vector.end(), 42);
	std_vector.insert(std_vector.begin(), 2, 21);
	ft_vector.print_vect();
    std_print(std_vector);

	ft_vector.insert(ft_vector.end() - 2, 42);
    std_vector.insert(std_vector.end() - 2, 42);
	ft_vector.print_vect();
    std_print(std_vector);

	ft_vector.insert(ft_vector.end(), 2, 84);
    std_vector.insert(std_vector.end(), 2, 84);
	ft_vector.print_vect();
    std_print(std_vector);

	ft_vector.resize(4);
    std_vector.resize(4);
	ft_vector.print_vect();
    std_print(std_vector);

	ft_vector.insert(ft_vector.begin() + 2, ft_vector.begin(), ft_vector.end());
	ft_vector.clear();
    std_vector.insert(std_vector.begin() + 2, std_vector.begin(), std_vector.end());
	std_vector.clear();

    ft_vector.print_vect();
    std_print(std_vector);

    for (int i = 0; i < 5; ++i)
		ft_vector.insert(ft_vector.end(), i);
	ft_vector.insert(ft_vector.begin() + 1, 2, 111);

    for (int i = 0; i < 5; ++i)
		std_vector.insert(std_vector.end(), i);
	std_vector.insert(std_vector.begin() + 1, 2, 111);

    ft_vector.print_vect();
    std_print(std_vector);

    ft_vector.clear();
    std_vector.clear();

    /*//std::cout << "---- TEST 5: get_allocator ---- " << std::endl;

    std::cout << "---- PART 2: ELEMENT ACCESS ---- " << std::endl;
    std::cout << "---- TEST 1: at ---- " << std::endl;
    std::cout << "ft_vector at 2: " << ft_vector.at(2);
    std::cout << "std_vector at 2: " << std_vector.at(2);
    std::cout << "---- TEST 2: operator[] ---- " << std::endl;
    std::cout << "---- TEST 3: front ---- " << std::endl;
    std::cout << "ft_vector : " << ft_vector.front() << std::endl;
    std::cout << "std_vector : " << std_vector.front() << std::endl;
    std::cout << "---- TEST 4: back ---- " << std::endl;
    std::cout << "ft_vector : " << ft_vector.back() << std::endl;
    std::cout << "std_vector : " << std_vector.back() << std::endl;
    std::cout << "---- TEST 5: data ---- " << std::endl;
    std::cout << "ft_vector: " << *ft_vector.data() << std::endl;
    std::cout << "std_vector: " << *std_vector.data() << std::endl;

    std::cout << "---- PART 3: ITERATORS ---- " << std::endl;
    std::cout << "---- TEST 1: begin ---- " << std::endl;
    std::cout << "ft_vector iterator begin: " << *ft_vector.begin() << std::endl;
    std::cout << "std_vector iterator begin: " << *std_vector.begin() << std::endl;
    std::cout << "---- TEST 2: end ---- " << std::endl;
    std::cout << "ft_vector iterator end: " << *ft_vector.end() << std::endl;
    std::cout << "std_vector iterator end: " << *std_vector.end() << std::endl;
    std::cout << "---- TEST 3: rbegin ---- " << std::endl;
    std::cout << "ft_vector iterator rbegin: " << *ft_vector.rbegin() << std::endl;
    std::cout << "std_vector iterator rbegin: " << *std_vector.rbegin() << std::endl;
    std::cout << "---- TEST 4: rend ---- " << std::endl;
    std::cout << "ft_vector iterator rend: " << *ft_vector.rend() << std::endl;
    std::cout << "std_vector iterator rend: " << *std_vector.rend() << std::endl;


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
    std::cout << "---- TEST 6: std::swap ---- " << std::endl;*/

    ft_vector.print_vect();
    std_print(std_vector);
    
}