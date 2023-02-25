#include <iostream>
#include <map>

/**
 * c++ -Wextra -Werror -Wall -std=c++98 std.cpp
 * ./a.out > std.txt  
 * ./ft_containers > ft.txt
 * cmp std.txt ft.txt 
*/
template<typename key, typename val>
void std_print(typename std::map<key, val> map, std::string name)
{
    typename std::map<key, val>::iterator begin = map.begin();
    std::cout << "--- content of : " << name << " ---\n";
    for (; begin != map.end(); begin++)
        std::cout << "first: " << begin->first << " second: " << begin->second << std::endl;
    std::cout << "map size: " << map.size() << std::endl << std::endl;
}

int main(void)
{
    std::cout << " =          constructors             =\n";
    std::cout << " ===================================== \n\n";
    std::map<int, char>  std_map;

    std_map[0] = 'a';
    std_map[1] = 'z';
    std_map[2] = 'b';


    std_print(std_map, "map");
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      copy constructor      \n";
    std::map<int, char> std_map_copy(std_map);
    std_print(std_map, "map");
    std_print(std_map_copy, "map_copy");
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      iterator constructor      \n";
    std::map<int, char>::iterator iter_begin = std_map.begin();
    std::map<int, char>::iterator iter_end = std_map.end();
    std::map<int, char> std_map_iter(iter_begin, iter_end);
    std_print(std_map, "map");
    std_print(std_map_iter, "map_iter");
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
    std_print(std_map, "map");
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
    //std::cout << "map at end(): " << std_iter->first << ", " << std_iter->second << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      rbegin() -> reverse iterator     \n";
    std::map<int, char>::reverse_iterator std_iter_rev = std_map.rbegin();
    std::cout << "map at begin(): " << std_iter_rev->first << ", " << std_iter_rev->second << std::endl << std::endl;
    std_iter_rev++;
    std::cout << "map at begin() ++ : " << std_iter_rev->first << ", " << std_iter_rev->second << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";


    std::cout << "      rend() -> reverse iterator     \n";
    std_iter_rev = std_map.rend();
    //std::cout << "map at end(): " << std_iter_rev->first << ", " << std_iter_rev->second << std::endl;
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
    std_print(std_map_copy, "before");
    std_map_copy.clear();
    std_print(std_map_copy, "after");
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      insert(val)      \n";
    std_print(std_map, "before");
    std::pair<int, char> pair = std::make_pair(8, 'f');
    std_map.insert(pair);
    std_print(std_map, "after");
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      insert(it1, it2)      \n";
    std_print(std_map, "before inserting [3, p], [11, q], [56, l] ");
    std::map<int, char>  other;
    other[3] = 'p';
    other[11] = 'q'; 
    other[56] = 'l';
    std_map.insert(other.begin(), other.end());
    std_print(std_map, "after");
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      erase(key)      \n";
    std_print(std_map, "before");
    std::cout << " erasing element at pos: begin++ (z) \n";
    std_iter = std_map.begin();
    std_iter++;
    std_map.erase(std_iter);
    std_print(std_map, "after");
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      erase(iter1, iter2)      \n";
    std_print(std_map, "before");
    std::cout << " erasing from pos 2 to 11\n" ;
    std::map<int, char>::iterator begin = std_map.find(2);
    std::map<int, char>::iterator end = std_map.find(11);
    std_map.erase(begin, end);
    std_print(std_map, "after");
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";


    std::cout << "      swap(map)      \n";
    std_print(other, "map1 before ");
    std_print(std_map, "map2 before ");
    std_map.swap(other);
    std_print(other, "map1 after ");
    std_print(std_map, "map2 after ");
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
    std_print(std_map, "std_map");
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
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

}
