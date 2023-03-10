#include "map.hpp"
#include "vector.hpp"
#include <list>
#include <map>
#include "stack.hpp"

/**
 * c++ -Wextra -Werror -Wall -std=c++98 std.cpp
 * ./a.out > std.txt  
 * ./ft_containers > ft.txt
 * cmp std.txt std.txt 
*/

template<typename key, typename val>
void ft_print_map(typename ft::map<key, val> map, std::string name)
{
    typename ft::map<key, val>::iterator begin = map.begin();
    std::cout << "--- content of : " << name << " ---\n";
    for (; begin != map.end(); begin++)
        std::cout << "first: " << begin->first << " second: " << begin->second << std::endl;   
    std::cout << "map size: " << map.size() << std::endl;
    std::cout << "map capcity: " << map.capcity() << std::endl << std::endl;
}

template<class T>
void ft_print_vector(ft::vector<T> vector, std::string name) 
{
    std::cout << "--- content of : " << name << " ---\n";
    typename ft::vector<T>::iterator it = vector.begin();
    for (;it != vector.end(); it++)
        std::cout << *(it) << std::endl;
    std::cout << "size: " << vector.size() << std::endl;
    std::cout << "capcity: " << vector.capacity() << std::endl << std::endl;
}

int main(void)
{

    std::cout << "* * * * * * * * * * * * * * * * * * * * \n";
    std::cout << "*                                     * \n";
    std::cout << "*             VECTOR                  * \n";
    std::cout << "*                                     * \n";
    std::cout << "* * * * * * * * * * * * * * * * * * * * \n\n˙";
    std::cout << " ===================================== \n";
    std::cout << " =          constructors             =\n";
    std::cout << " ===================================== \n\n";

    std::cout << "      initialized constructor      \n";
    ft::vector<char> ft_vector(3, 'c');
    ft_print_vector(ft_vector, "vector");
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      copy constructor      \n";
    ft::vector<char> ft_vector_copy(ft_vector);
    ft_print_vector(ft_vector, "vector copy");
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "       constructor with iterator range    \n";
    ft::vector<char>::iterator it_begin = ft_vector.begin();
    ft::vector<char>::iterator it_end = ft_vector.end();
    ft::vector<char> ft_vector_it(it_begin, it_end);
    ft_print_vector(ft_vector_it, "vector iterator range");
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << " ===================================== \n";
    std::cout << " =          member functions         =\n";
    std::cout << " ===================================== \n\n";
    std::cout << "      operator =       \n";
    ft::vector<char> ft_vector_equal;
    ft_vector_equal = ft_vector;
    ft_print_vector(ft_vector_equal, "vector equal");
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      assign(size, value_type)      \n";
    ft_print_vector(ft_vector, "before");
    ft_vector.assign(4, 'g');
    ft_print_vector(ft_vector, "after assigning 4 times 'g' ");
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      assign(it, it)      \n";
    ft_vector.assign(ft_vector_copy.begin(), ft_vector_copy.end());
    ft_print_vector(ft_vector, "after assigning ");
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    ft_vector.push_back('o');
    ft_vector.push_back('l');
    ft_vector.push_back('l');
    ft_vector.push_back('a');
    ft_print_vector(ft_vector, "vector");
    //std::cout << "      at()     \n";

    std::cout << "      operator[]     \n";
    std::cout << "vector at pos 3: " << ft_vector[3] << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      front()     \n";
    std::cout << "vector at front pos : " << ft_vector.front() << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      const front()     \n";
    ft::vector<char>::const_reference refFront = ft_vector.front();
    std::cout << "vector at const front pos : " << refFront << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      back()     \n";
    std::cout << "vector at back pos : " << ft_vector.back() << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      const back()     \n";
    ft::vector<char>::const_reference refBack = ft_vector.back();
    std::cout << "vector at back pos : " << refBack << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      data()     \n";
    ft::vector<char>::pointer data = ft_vector.data();
    std::cout << "vector data: " << data << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "     const data()     \n";
    ft::vector<char>::const_pointer dataConst = ft_vector.data();
    std::cout << "vector data: " << dataConst << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    


    std::cout << " ===================================== \n";
    std::cout << " =          iterators                =\n";
    std::cout << " ===================================== \n\n";

    std::cout << "      begin()     \n";
    ft::vector<char>::iterator beg = ft_vector.begin();
    std::cout << "vector at iterator begin : " << *(beg) << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      const begin()     \n";
    ft::vector<char>::const_iterator const_beg = ft_vector.begin();
    std::cout << "vector at iterator begin : " << *(const_beg) << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      end()     \n";
    ft::vector<char>::iterator end = ft_vector.begin();
    std::cout << "vector at iterator end++ : " << *(end)++ << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      const end()     \n";
    ft::vector<char>::const_iterator const_end = ft_vector.begin();
    std::cout << "vector at iterator end++ : " << *(const_end)++ << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      rbegin()     \n";
    ft::vector<char>::reverse_iterator rbeg = ft_vector.rbegin();
    std::cout << "vector at iterator rbeg : " << *(rbeg)++ << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      const rbegin()     \n";
    ft::vector<char>::const_reverse_iterator const_rbeg = ft_vector.rbegin();
    std::cout << "vector at iterator rbeg : " << *(const_rbeg)++ << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      rend()     \n";
    ft::vector<char>::reverse_iterator rend = ft_vector.rend();
    std::cout << "vector at iterator rend : " << *(rend)++ << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      const rend()     \n";
    ft::vector<char>::const_reverse_iterator const_rend = ft_vector.rend();
    std::cout << "vector at iterator rend : " << *(const_rend)++ << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";


    std::cout << " ===================================== \n";
    std::cout << " =          capacity                 =\n";
    std::cout << " ===================================== \n\n";
    std::cout << "      empty()     \n";
    std::cout << "vector is empty: " << ft_vector.empty();
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      size()     \n";
    std::cout << "vector size: " << ft_vector.size();
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      reserve() / capcity()    \n";
    std::cout << "vector capacity before: " << ft_vector.capacity();
    ft_vector.reserve(4);
    std::cout << "vector capacity after reserving 4: " << ft_vector.capacity();
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      clear()    \n";
    ft_vector.clear();
    ft_print_vector(ft_vector, "vector cleared");
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    /*std::cout << "      insert(iter, iter)    \n";
    ft::vector<char>::iterator iter_beg = ft_vector.begin();
    iter_beg++;
    std::cout << *(beg) << ", " << *(iter_beg) << ", " << *(end) << std::endl;
    ft_vector.insert(iter_beg, it, end);
    ft_print_vector(ft_vector, "vector after re-inserting");
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";*/

    std::cout << "      insert(pos, nm val)    \n";

    ft_vector.insert(ft_vector.begin(), 3, 'p');
    ft_print_vector(ft_vector, "vector after inserting 3 times 'p' ");
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      insert(pos, val)    \n";
    ft_vector.insert(ft_vector.begin(), 'x');
    ft_print_vector(ft_vector, "vector after inserting x ");
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      erase(pos)    \n";
    ft_vector.erase(ft_vector.begin());
    ft_print_vector(ft_vector, "vector after ersase" ) ;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    /*std::cout << "      erase()    \n";
    ft::vector<char>::iterator it_erase = ft_vector.begin();
    ft::vector<char>::iterator it2_erase(it_erase);
    ++it2_erase;
    ft_vector.erase(it2_erase, it_erase);
    ft_print_vector(ft_vector, "vector ater erase");
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";*/

    std::cout << "      puch_back()    \n";
    ft_print_vector(ft_vector, "vector before push back" ) ;
    ft_vector.push_back('1');
    ft_vector.push_back('2');
    ft_vector.push_back('3');
    ft_print_vector(ft_vector, "vector after push back" ) ;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      pop_back()    \n";
    ft_print_vector(ft_vector, "vector before pop back" ) ;
    ft_vector.pop_back();
    ft_vector.pop_back();
    ft_print_vector(ft_vector, "vector after pop back" ) ;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      resize()    \n";
    ft_vector.resize(2, 'r');
    ft_print_vector(ft_vector, "vector resize");
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    ft::vector<char> ft_vect2;
    ft_vect2.push_back('l');
    ft_vect2.push_back('a');
    ft_vect2.push_back('l');
    ft_vect2.push_back('a');

    std::cout << "      swap()    \n";
    ft_print_vector(ft_vector, "vector 1");
    ft_print_vector(ft_vect2, "vector 2");
    ft_vector.swap(ft_vect2);
    ft_print_vector(ft_vector, "vector 1");
    ft_print_vector(ft_vect2, "vector 2");

    std::cout << " ===================================== \n";
    std::cout << " =          constructors             =\n";
    std::cout << " ===================================== \n\n";
    
    std::cout << "* * * * * * * * * * * * * * * * * * * * \n";
    std::cout << "*                                     * \n";
    std::cout << "*             STACK                   * \n";
    std::cout << "*                                     * \n";
    std::cout << "* * * * * * * * * * * * * * * * * * * * \n\n˙";
    std::cout << " ===================================== \n\n";
    std::cout << " =          constructors             =\n";
    std::cout << " ===================================== \n\n";






    /*std::cout << "* * * * * * * * * * * * * * * * * * * * \n";
    std::cout << "*                                     * \n";
    std::cout << "*             MAP                     * \n";
    std::cout << "*                                     * \n";
    std::cout << "* * * * * * * * * * * * * * * * * * * * \n\n˙";
    std::cout << " ===================================== \n\n";
    std::cout << " =          constructors             =\n";
    std::cout << " ===================================== \n\n";
    ft::map<int, char>  ft_map;

    ft_map[0] = 'a';
    ft_map[1] = 'z';
    ft_map[2] = 'b';


    ft_print_map(ft_map, "map");
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      copy constructor      \n";
    ft::map<int, char> ft_map_copy(ft_map);
    ft_print_map(ft_map, "map");
    ft_print_map(ft_map_copy, "map_copy");
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      iterator constructor      \n";
    ft::map<int, char>::iterator iter_begin = ft_map.begin();
    ft::map<int, char>::iterator iter_end = ft_map.end();
    ft::map<int, char> ft_map_iter(iter_begin, iter_end);
    ft_print_map(ft_map, "map");
    ft_print_map(ft_map_iter, "map_iter");
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";


    std::cout << " ===================================== \n";
    std::cout << " =          element access           =\n";
    std::cout << " ===================================== \n\n";
    std::cout << "      at      \n";
    std::cout << "map value at key 2: " << ft_map.at(2) << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      operator[]      \n";
    std::cout << "map value at [2]: " << ft_map[2] << std::endl;
    std::cout << "-> add val t at [4]" << std::endl;
    ft_map[4] = 't';
    ft_print_map(ft_map, "map");
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << " ===================================== \n";
    std::cout << " =          iterators                =\n";
    std::cout << " ===================================== \n\n";
    std::cout << "      begin()      \n";
    ft::map<int, char>::iterator ft_iter = ft_map.begin();
    std::cout << "map at begin(): " << ft_iter->first << ", " << ft_iter->second << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      end()      \n";
    ft_iter = ft_map.end();
    ft_iter--;
    std::cout << "map at end(): " << ft_iter->first << ", " << ft_iter->second << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      rbegin() -> reverse iterator     \n";
    ft::map<int, char>::reverse_iterator ft_iter_rev = ft_map.rbegin();
    std::cout << "map at begin(): " << ft_iter_rev->first << ", " << ft_iter_rev->second << std::endl << std::endl;
    ft_iter_rev++;
    std::cout << "map at begin() ++ : " << ft_iter_rev->first << ", " << ft_iter_rev->second << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";


    std::cout << "      rend() -> reverse iterator     \n";
    ft_iter_rev = ft_map.rend()++;
    std::cout << "map at end(): " << ft_iter_rev->first << ", " << ft_iter_rev->second << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << " ===================================== \n";
    std::cout << " =          capcity                  =\n";
    std::cout << " ===================================== \n\n";
    std::cout << "      empty()     \n";
    std::cout << "map: " << ft_map.empty() << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";
    std::cout << "      size()     \n";
    std::cout << "map: " << ft_map.size() << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << " ===================================== \n";
    std::cout << " =          modifiers                  =\n";
    std::cout << " ===================================== \n\n";
    std::cout << "      clear()     \n";
    ft_print_map(ft_map_copy, "before");
    ft_map_copy.clear();
    ft_print_map(ft_map_copy, "after");
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      insert(val)      \n";
    ft_print_map(ft_map, "before");
    ft::pair<int, char> pair = ft::make_pair(8, 'f');
    ft_map.insert(pair);
    ft_print_map(ft_map, "after");
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      insert(it1, it2)      \n";
    ft_print_map(ft_map, "before inserting [3, p], [11, q], [56, l] ");
    ft::map<int, char>  other;
    other[3] = 'p';
    other[11] = 'q'; 
    other[56] = 'l';
    ft_map.insert(other.begin(), other.end());
    ft_print_map(ft_map, "after");
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      erase(key)      \n";
    ft_print_map(ft_map, "before");
    std::cout << " erasing element at pos: begin++ (z) \n";
    ft_iter = ft_map.begin();
    ft_iter++;
    ft_map.erase(ft_iter);
    ft_print_map(ft_map, "after");
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      erase(iter1, iter2)      \n";
    ft_print_map(ft_map, "before");
    std::cout << " erasing from pos 2 to 11\n" ;
    ft::map<int, char>::iterator begin = ft_map.find(2);
    ft::map<int, char>::iterator end = ft_map.find(11);
    ft_map.erase(begin, end);
    ft_print_map(ft_map, "after");
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";


    std::cout << "      swap(map)      \n";
    ft_print_map(other, "map1 before ");
    ft_print_map(ft_map, "map2 before ");
    ft_map.swap(other);
    ft_print_map(other, "map1 after ");
    ft_print_map(ft_map, "map2 after ");
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      count()      \n"; 
    std::cout << " number of key 64 in map: " << ft_map.count(64) << std::endl;
    std::cout << " number of key 3 in map: " << ft_map.count(3) << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    ft_map[8] = 'j';
    ft_map[4] = 'e';

    std::cout << "      find(key)      \n"; 
    ft_iter = ft_map.find(3);
    std::cout << "element at found in map with key 3: " << ft_iter->first << ", " << ft_iter->second << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << " ===================================== \n";
    std::cout << " =          lookup                   =\n";
    std::cout << " ===================================== \n\n";
    std::cout << "      lower_bound(key)      \n";
    ft_print_map(ft_map, "ft_map");
    ft_iter = ft_map.lower_bound(8); 
    std::cout << "ft lower bound of 8: " << ft_iter->first << ", " << ft_iter->second << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";
    
    std::cout << "      upper_bound(key)      \n"; 
    ft_iter = ft_map.upper_bound(8); 
    std::cout << "ft upper bound of 8: " << ft_iter->first << ", " << ft_iter->second << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      equal_range(key)      \n";
    ft::pair<ft::map<int, char>::iterator, ft::map<int, char>::iterator> ft_range = ft_map.equal_range(8);
    std::cout << "ft range for key 8: " << ft_range.first->first << " to " << ft_range.second->first << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";*/

}