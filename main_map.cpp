#include "map.hpp"
#include "test.hpp"
#include <iostream>
#include <map>

template<typename key, typename val>
void ft_print(typename ft::map<key, val> map, std::string name)
{
    typename ft::map<key, val>::iterator begin = map.begin();
    std::cout << "--- content of : " << name << " ---\n";
    for (; begin != map.end(); begin++)
        std::cout << "first: " << begin->first << " second: " << begin->second << std::endl;   
    std::cout << "map size: " << map.size() << std::endl << std::endl;
}

int main(void)
{
    std::cout << " =          constructors             =\n";
    std::cout << " ===================================== \n\n";
    ft::map<int, char>  ft_map;

    ft_map[0] = 'a';
    ft_map[1] = 'z';
    ft_map[2] = 'b';


    ft_print(ft_map, "map");
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      copy constructor      \n";
    ft::map<int, char> ft_map_copy(ft_map);
    ft_print(ft_map, "map");
    ft_print(ft_map_copy, "map_copy");
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      iterator constructor      \n";
    ft::map<int, char>::iterator iter_begin = ft_map.begin();
    ft::map<int, char>::iterator iter_end = ft_map.end();
    ft::map<int, char> ft_map_iter(iter_begin, iter_end);
    ft_print(ft_map, "map");
    ft_print(ft_map_iter, "map_iter");
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
    ft_print(ft_map, "map");
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
    //std::cout << "map at end(): " << ft_iter->first << ", " << ft_iter->second << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      rbegin() -> reverse iterator     \n";
    ft::map<int, char>::reverse_iterator ft_iter_rev = ft_map.rbegin();
    std::cout << "map at begin(): " << ft_iter_rev->first << ", " << ft_iter_rev->second << std::endl << std::endl;
    ft_iter_rev++;
    std::cout << "map at begin() ++ : " << ft_iter_rev->first << ", " << ft_iter_rev->second << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";


    std::cout << "      rend() -> reverse iterator     \n";
    ft_iter_rev = ft_map.rend();
    //std::cout << "map at end(): " << ft_iter_rev->first << ", " << ft_iter_rev->second << std::endl;
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

    std::cout << "      find(key)      \n"; 
    ft_iter = ft_map.find(3);
    std::cout << "element at found in map with key 3: " << ft_iter->first << ", " << ft_iter->second << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << " ===================================== \n";
    std::cout << " =          lookup                   =\n";
    std::cout << " ===================================== \n\n";
    std::cout << "      lower_bound(key)      \n";
    ft_print(ft_map, "ft_map");
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
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

}