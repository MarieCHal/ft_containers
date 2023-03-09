#include <vector>
#include <map>
#include <stack>
#include <iostream>

template<typename key, typename val>
void std_print_map(typename std::map<key, val> map, std::string name)
{
    typename std::map<key, val>::iterator begin = map.begin();
    std::cout << "--- content of : " << name << " ---\n";
    for (; begin != map.end(); begin++)
        std::cout << "first: " << begin->first << " second: " << begin->second << std::endl;
    std::cout << "map size: " << map.size() << std::endl << std::endl;
}

template<class T>
void std_print_vector(std::vector<T> vector, std::string name) 
{
    std::cout << "--- content of : " << name << " ---\n";
    typename std::vector<T>::iterator it = vector.begin();
    for (;it != vector.end(); it++)
        std::cout << *(it) << std::endl;
    std::cout << "size: " << vector.size() << std::endl << std::endl;
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
    std::vector<char> std_vector(3, 'c');
    std_print_vector(std_vector, "vector");
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      copy constructor      \n";
    std::vector<char> std_vector_copy(std_vector);
    std_print_vector(std_vector, "vector copy");
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "       constructor with iterator range    \n";
    std::vector<char>::iterator it_begin = std_vector.begin();
    std::vector<char>::iterator it_end = std_vector.end();
    std::vector<char> std_vector_it(it_begin, it_end);
    std_print_vector(std_vector_it, "vector iterator range");
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << " ===================================== \n";
    std::cout << " =          member functions         =\n";
    std::cout << " ===================================== \n\n";
    std::cout << "      operator =       \n";
    std::vector<char> std_vector_equal;
    std_vector_equal = std_vector;
    std_print_vector(std_vector_equal, "vector equal");
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      assign(size, value_type)      \n";
    std_print_vector(std_vector, "before");
    std_vector.assign(4, 'g');
    std_print_vector(std_vector, "astder assigning 4 times 'g' ");
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      assign(it, it)      \n";
    std_vector.assign(std_vector_copy.begin(), std_vector_copy.end());
    std_print_vector(std_vector, "astder assigning ");
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";
    
    //std::cout << "      at()     \n";

    std::cout << "      operator[]     \n";
    std::cout << "vector at pos 3: " << std_vector[3] << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      front()     \n";
    std::cout << "vector at front pos : " << std_vector.front() << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      const front()     \n";
    std::vector<char>::const_reference refFront = std_vector.front();
    std::cout << "vector at const front pos : " << refFront << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      back()     \n";
    std::cout << "vector at back pos : " << std_vector.back() << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      const back()     \n";
    std::vector<char>::const_reference refBack = std_vector.back();
    std::cout << "vector at back pos : " << refBack << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      data()     \n";
    std::vector<char>::pointer data = std_vector.data();
    std::cout << "vector data: " << data << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "     const data()     \n";
    std::vector<char>::const_pointer dataConst = std_vector.data();
    std::cout << "vector data: " << dataConst << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    


    std::cout << " ===================================== \n";
    std::cout << " =          iterators                =\n";
    std::cout << " ===================================== \n\n";

    std::cout << "      begin()     \n";
    std::vector<char>::iterator beg = std_vector.begin();
    std::cout << "vector at iterator begin : " << *(beg) << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      const begin()     \n";
    std::vector<char>::const_iterator const_beg = std_vector.begin();
    std::cout << "vector at iterator begin : " << *(const_beg) << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      end()     \n";
    std::vector<char>::iterator end = std_vector.begin();
    std::cout << "vector at iterator end++ : " << *(end)++ << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      const end()     \n";
    std::vector<char>::const_iterator const_end = std_vector.begin();
    std::cout << "vector at iterator end++ : " << *(const_end)++ << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      rbegin()     \n";
    std::vector<char>::reverse_iterator rbeg = std_vector.rbegin();
    std::cout << "vector at iterator rbeg : " << *(rbeg)++ << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      const rbegin()     \n";
    std::vector<char>::const_reverse_iterator const_rbeg = std_vector.rbegin();
    std::cout << "vector at iterator rbeg : " << *(const_rbeg)++ << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      rend()     \n";
    std::vector<char>::reverse_iterator rend = std_vector.rend();
    std::cout << "vector at iterator rend : " << *(rend)++ << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      const rend()     \n";
    std::vector<char>::const_reverse_iterator const_rend = std_vector.rend();
    std::cout << "vector at iterator rend : " << *(const_rend)++ << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";


    std::cout << " ===================================== \n";
    std::cout << " =          capacity                 =\n";
    std::cout << " ===================================== \n\n";
    std::cout << "      empty()     \n";
    std::cout << "vector is empty: " << std_vector.empty();
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      size()     \n";
    std::cout << "vector size: " << std_vector.size();
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      reserve() / capcity()    \n";
    std::cout << "vector capacity before: " << std_vector.capacity();
    std_vector.reserve(4);
    std::cout << "vector capacity astder reserving 4: " << std_vector.capacity();
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      clear()    \n";
    std_vector.clear();
    std_print_vector(std_vector, "vector cleared");
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      insert(iter, iter)    \n";
    std::vector<char>::iterator iter_beg = std_vector.begin();
    std_vector.insert(beg, iter_beg, end);
    std_print_vector(std_vector, "vector astder re-inserting");
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      insert(pos, nm val)    \n";
    std_vector.insert(beg++, 3, 'p');
    std_print_vector(std_vector, "vector astder inserting 3 times 'p' ");
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      insert(pos, val)    \n";
    std_vector.insert(std_vector.begin(), 'x');
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      erase(pos)    \n";
    //std_vector.erase((std_vector.rbegin())++);
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      clear()    \n";
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    /*std::cout << "* * * * * * * * * * * * * * * * * * * * \n";
    std::cout << "*                                     * \n";
    std::cout << "*             MAP                     * \n";
    std::cout << "*                                     * \n";
    std::cout << "* * * * * * * * * * * * * * * * * * * * \n\n˙";
    std::cout << " ===================================== \n\n";
    std::cout << " =          constructors             =\n";
    std::cout << " ===================================== \n\n";
    std::map<int, char>  std_map;

    std_map[0] = 'a';
    std_map[1] = 'z';
    std_map[2] = 'b';


    std_print_map(std_map, "map");
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      copy constructor      \n";
    std::map<int, char> std_map_copy(std_map);
    std_print_map(std_map, "map");
    std_print_map(std_map_copy, "map_copy");
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      iterator constructor      \n";
    std::map<int, char>::iterator iter_begin = std_map.begin();
    std::map<int, char>::iterator iter_end = std_map.end();
    std::map<int, char> std_map_iter(iter_begin, iter_end);
    std_print_map(std_map, "map");
    std_print_map(std_map_iter, "map_iter");
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";


    std::cout << " ===================================== \n";
    std::cout << " =          element access           =\n";
    std::cout << " ===================================== \n\n";
    std::cout << "      at      \n";
    std::cout << "map value at key 2: " << std_map.at(2) << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      operator[]      \n";
    std::cout << "map value at [2]: " << std_map[2] << std::endl;
    std::cout << "-> add val t at [4]" << std::endl;
    std_map[4] = 't';
    std_print_map(std_map, "map");
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << " ===================================== \n";
    std::cout << " =          iterators                =\n";
    std::cout << " ===================================== \n\n";
    std::cout << "      begin()      \n";
    std::map<int, char>::iterator std_iter = std_map.begin();
    std::cout << "map at begin(): " << std_iter->first << ", " << std_iter->second << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      end()      \n";
    std_iter = std_map.end();
    std_iter--;
    std::cout << "map at end(): " << std_iter->first << ", " << std_iter->second << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      rbegin() -> reverse iterator     \n";
    std::map<int, char>::reverse_iterator std_iter_rev = std_map.rbegin();
    std::cout << "map at begin(): " << std_iter_rev->first << ", " << std_iter_rev->second << std::endl << std::endl;
    std_iter_rev++;
    std::cout << "map at begin() ++ : " << std_iter_rev->first << ", " << std_iter_rev->second << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";


    std::cout << "      rend() -> reverse iterator     \n";
    std_iter_rev = std_map.rend()++;
    std::cout << "map at end(): " << std_iter_rev->first << ", " << std_iter_rev->second << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << " ===================================== \n";
    std::cout << " =          capcity                  =\n";
    std::cout << " ===================================== \n\n";
    std::cout << "      empty()     \n";
    std::cout << "map: " << std_map.empty() << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";
    std::cout << "      size()     \n";
    std::cout << "map: " << std_map.size() << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << " ===================================== \n";
    std::cout << " =          modifiers                  =\n";
    std::cout << " ===================================== \n\n";
    std::cout << "      clear()     \n";
    std_print_map(std_map_copy, "before");
    std_map_copy.clear();
    std_print_map(std_map_copy, "astder");
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      insert(val)      \n";
    std_print_map(std_map, "before");
    std::pair<int, char> pair = std::make_pair(8, 'f');
    std_map.insert(pair);
    std_print_map(std_map, "astder");
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      insert(it1, it2)      \n";
    std_print_map(std_map, "before inserting [3, p], [11, q], [56, l] ");
    std::map<int, char>  other;
    other[3] = 'p';
    other[11] = 'q'; 
    other[56] = 'l';
    std_map.insert(other.begin(), other.end());
    std_print_map(std_map, "astder");
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      erase(key)      \n";
    std_print_map(std_map, "before");
    std::cout << " erasing element at pos: begin++ (z) \n";
    std_iter = std_map.begin();
    std_iter++;
    std_map.erase(std_iter);
    std_print_map(std_map, "astder");
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      erase(iter1, iter2)      \n";
    std_print_map(std_map, "before");
    std::cout << " erasing from pos 2 to 11\n" ;
    std::map<int, char>::iterator begin = std_map.find(2);
    std::map<int, char>::iterator end = std_map.find(11);
    std_map.erase(begin, end);
    std_print_map(std_map, "astder");
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";


    std::cout << "      swap(map)      \n";
    std_print_map(other, "map1 before ");
    std_print_map(std_map, "map2 before ");
    std_map.swap(other);
    std_print_map(other, "map1 astder ");
    std_print_map(std_map, "map2 astder ");
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      count()      \n"; 
    std::cout << " number of key 64 in map: " << std_map.count(64) << std::endl;
    std::cout << " number of key 3 in map: " << std_map.count(3) << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std_map[8] = 'j';
    std_map[4] = 'e';

    std::cout << "      find(key)      \n"; 
    std_iter = std_map.find(3);
    std::cout << "element at found in map with key 3: " << std_iter->first << ", " << std_iter->second << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << " ===================================== \n";
    std::cout << " =          lookup                   =\n";
    std::cout << " ===================================== \n\n";
    std::cout << "      lower_bound(key)      \n";
    std_print_map(std_map, "std_map");
    std_iter = std_map.lower_bound(8); 
    std::cout << "std lower bound of 8: " << std_iter->first << ", " << std_iter->second << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";
    
    std::cout << "      upper_bound(key)      \n"; 
    std_iter = std_map.upper_bound(8); 
    std::cout << "std upper bound of 8: " << std_iter->first << ", " << std_iter->second << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      equal_range(key)      \n";
    std::pair<std::map<int, char>::iterator, std::map<int, char>::iterator> std_range = std_map.equal_range(8);
    std::cout << "std range for key 8: " << std_range.first->first << " to " << std_range.second->first << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";*/
}
