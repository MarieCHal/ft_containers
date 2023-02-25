#include "map.hpp"
#include "test.hpp"
#include <iostream>
#include <map>

template<typename key, typename val>
void std_print(typename std::map<key, val> map, std::string name)
{
    typename std::map<key, val>::iterator begin = map.begin();
    std::cout << "--- STD: " << name << " ---\n";
    for (; begin != map.end(); begin++)
        std::cout << "first: " << begin->first << " second: " << begin->second << std::endl;
    std::cout << "map size: " << map.size() << std::endl << std::endl;
}

template<typename key, typename val>
void ft_print(typename ft::map<key, val> map, std::string name)
{
    typename ft::map<key, val>::iterator begin = map.begin();
    std::cout << "--- FT: " << name << " ---\n";
    for (; begin != map.end(); begin++)
        std::cout << "first: " << begin->first << " second: " << begin->second << std::endl;   
    std::cout << "map size: " << map.size() << std::endl << std::endl;
}

int main(void)
{
    /*ft::Node<ft::pair<int, std::string> > test;

    ft::pair<int, std::string> content(-3, "coucou");
    ft::map<int, std::string> testMap;
    ft::pair<int, std::string> insertInMap = ft::make_pair(1, "tesssst");
    testMap.insert(insertInMap);
    insertInMap = ft::make_pair(2, "tesssst2");
    testMap.insert(insertInMap);
    testMap.insert(content);
    ft::map<int, std::string>::iterator iter = testMap.begin();
    std::cout << "first element in map: " << iter->second << std::endl;
    iter++;
    std::cout << "seccond element in map: " << iter->second << std::endl;
    iter++;
    std::cout << "seccond element in map: " << iter->second << std::endl;
    try {
        testMap.insert(content);
    }
    catch (){

    }*/
    /*std::cout << "**** end() ****" << std::endl;
    std::cout << "FT -> first: " << ft_iter->first << ", ft seccond: " << ft_iter->second << std::endl;
    std::cout << "STD -> first: " << std_iter->first << ", std second: " << std_iter->second << std::endl;
    std::cout << std::endl;

    std_iter = std_map.begin();
    ft_iter = ft_map.begin();

    std::cout << "--- begin() ---" << std::endl;
    std::cout << "FT -> first: " << ft_iter->first << ", ft seccond: " << ft_iter->second << std::endl;
    std::cout << "STD -> first: " << std_iter->first << ", std second: " << std_iter->second << std::endl;
    std::cout << std::endl;


    std::cout << "--- end() ---" << std::endl;
    ft::map<int, char>::iterator ft_iter_end = ft_map.end();
    std::map<int, char>::iterator std_iter_end = std_map.end();

    std::cout << "ft: " << ft_iter_end->first << std::endl;
    std::cout << "std: " << std_iter_end->first << std::endl;*/


    /*ft::Node<ft::pair<int, std::string> > test;
    ft::pair<int, std::string> totest = ft::make_pair('3', "thisisatest");
    test.data = totest;
    ft::Node<ft::pair<int, std::string> >::node_ptr ptr = &ft::Node<ft::pair<int, std::string> >::nil;
    if (test != ft::Node<ft::pair<int, std::string> >::nil)
        std::cout << "test ok\n";
    if (ptr == &ft::Node<ft::pair<int, std::string> >::nil)
        std::cout << "test 2 ok\n";*/

    std::cout << " ===================================== \n";
    std::cout << " =          constructors             =\n";
    std::cout << " ===================================== \n\n";
    std::map<int, char> std_map;
    ft::map<int, char>  ft_map;

    std_map[0] = 'a';
    std_map[1] = 'z';
    std_map[2] = 'b';

    ft_map[0] = 'a';
    ft_map[1] = 'z';
    ft_map[2] = 'b';


    ft_print(ft_map, "ft_map");
    std_print(std_map, "std_map");
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      copy constructor      \n";
    ft::map<int, char> ft_map_copy(ft_map);
    ft_print(ft_map, "ft_map");
    ft_print(ft_map_copy, "ft_map_copy");
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      iterator constructor      \n";
    ft::map<int, char>::iterator iter_begin = ft_map.begin();
    ft::map<int, char>::iterator iter_end = ft_map.end();
    ft::map<int, char> ft_map_iter(iter_begin, iter_end);
    ft_print(ft_map, "ft_map");
    ft_print(ft_map_iter, "ft_map_iter");
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";


    std::cout << " ===================================== \n";
    std::cout << " =          element access           =\n";
    std::cout << " ===================================== \n\n";
    std::cout << "      at      \n";
    std::cout << "map_std value at key 2: " << std_map.at(2) << std::endl;
    std::cout << "map_ft value at key 2: " << ft_map.at(2) << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      operator[]      \n";
    std::cout << "map_std value at [2]: " << std_map[2] << std::endl;
    std::cout << "map_ft value at [2]: " << ft_map[2] << std::endl;
    std::cout << "-> add val t at [4]" << std::endl;
    std_map[4] = 't';
    ft_map[4] = 't';
    ft_print(ft_map, "ft_map");
    std_print(std_map, "std_map");
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << " ===================================== \n";
    std::cout << " =          iterators                =\n";
    std::cout << " ===================================== \n\n";
    std::cout << "      begin()      \n";
    std::map<int, char>::iterator std_iter = std_map.begin();
    ft::map<int, char>::iterator ft_iter = ft_map.begin();
    std::cout << "std_map at begin(): " << std_iter->first << ", " << std_iter->second << std::endl;
    std::cout << "ft_map at begin(): " << ft_iter->first << ", " << ft_iter->second << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      end()      \n";
    std_iter = std_map.end();
    ft_iter = ft_map.end();
    std::cout << "std_map at end(): " << std_iter->first << ", " << std_iter->second << std::endl;
    std::cout << "ft_map at end(): " << ft_iter->first << ", " << ft_iter->second << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      rbegin() -> reverse iterator     \n";
    std::map<int, char>::reverse_iterator std_iter_rev = std_map.rbegin();
    ft::map<int, char>::reverse_iterator ft_iter_rev = ft_map.rbegin();
    std::cout << "std_map at rbegin(): " << std_iter_rev->first << ", " << std_iter_rev->second << std::endl;
    std::cout << "ft_map at begin(): " << ft_iter_rev->first << ", " << ft_iter_rev->second << std::endl << std::endl;
    std_iter_rev++;
    ft_iter_rev++;
    std::cout << "std_map at rbegin() ++: " << std_iter_rev->first << ", " << std_iter_rev->second << std::endl;
    std::cout << "ft_map at begin() ++ : " << ft_iter_rev->first << ", " << ft_iter_rev->second << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";


    std::cout << "      rend() -> reverse iterator     \n";
    std_iter_rev = std_map.rend();
    ft_iter_rev = ft_map.rend();
    std::cout << "std_map at end(): " << std_iter_rev->first << ", " << std_iter_rev->second << std::endl;
    std::cout << "ft_map at end(): " << ft_iter_rev->first << ", " << ft_iter_rev->second << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << " ===================================== \n";
    std::cout << " =          capcity                  =\n";
    std::cout << " ===================================== \n\n";
    std::cout << "      empty()     \n";
    std::cout << "std_map: " << std_map.empty() << std::endl;
    std::cout << "ft_map: " << ft_map.empty() << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";
    std::cout << "      size()     \n";
    std::cout << "std_map: " << std_map.size() << std::endl;
    std::cout << "ft_map: " << ft_map.size() << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << " ===================================== \n";
    std::cout << " =          modifiers                  =\n";
    std::cout << " ===================================== \n\n";
    std::cout << "      clear()     \n";
    ft_print(ft_map_copy, "before");
    ft_map_copy.clear();
    ft_print(ft_map_copy, "after");
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      insert(val)      \n";
    ft_print(ft_map, "before");
    ft::pair<int, char> pair = ft::make_pair(8, 'f');
    ft_map.insert(pair);
    ft_print(ft_map, "after");
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      insert(it1, it2)      \n";
    ft_print(ft_map, "before inserting [3, p], [11, q], [56, l] ");
    ft::map<int, char>  other;
    other[3] = 'p';
    other[11] = 'q'; 
    other[56] = 'l';
    ft_map.insert(other.begin(), other.end());
    ft_print(ft_map, "after");
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      erase(key)      \n";
    ft_print(ft_map, "before");
    std::cout << " erasing element at pos: begin++ (z) \n";
    ft_iter = ft_map.begin();
    ft_iter++;
    ft_map.erase(ft_iter);
    ft_print(ft_map, "after");
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      erase(iter1, iter2)      \n";
    ft_print(ft_map, "before");
    std::cout << " erasing from pos 2 to 11\n" ;
    ft::map<int, char>::iterator begin = ft_map.find(2);
    ft::map<int, char>::iterator end = ft_map.find(11);
    ft_map.erase(begin, end);
    ft_print(ft_map, "after");
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";


    std::cout << "      swap(map)      \n";
    ft_print(other, "map1 before ");
    ft_print(ft_map, "map2 before ");
    ft_map.swap(other);
    ft_print(other, "map1 after ");
    ft_print(ft_map, "map2 after ");
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      count()      \n"; 
    std::cout << " number of key 64 in map: " << ft_map.count(64) << std::endl;
    std::cout << " number of key 3 in map: " << ft_map.count(3) << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    ft_map[8] = 'j';
    ft_map[4] = 'e';

    std_map.clear();
    std_map[3] = 'p';
    std_map[4] = 'e';
    std_map[8] = 'j';
    std_map[11] = 'q';
    std_map[56] = 'l';

    std::cout << "      find(key)      \n"; 
    ft_iter = ft_map.find(3);
    std::cout << "element at found in map with key 3: " << ft_iter->first << ", " << ft_iter->second << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      lower_bound(key)      \n";
    ft_print(ft_map, "ft_map");
    ft_iter = ft_map.lower_bound(8); 
    std::cout << "ft lower bound of 8: " << ft_iter->first << ", " << ft_iter->second << std::endl;
    std_iter = std_map.lower_bound(8); 
    std::cout << "std lower bound of 8: " << std_iter->first << ", " << std_iter->second << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";
    
    std::cout << "      upper_bound(key)      \n"; 
    ft_iter = ft_map.upper_bound(8); 
    std::cout << "ft upper bound of 8: " << ft_iter->first << ", " << ft_iter->second << std::endl;
    std_iter = std_map.upper_bound(8); 
    std::cout << "std upper bound of 8: " << std_iter->first << ", " << std_iter->second << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      equal_range(key)      \n"; 

}