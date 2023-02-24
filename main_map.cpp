#include "map.hpp"
#include "test.hpp"
#include <iostream>
#include <map>

template<typename key, typename val>
void std_print(typename std::map<key, val> map)
{
    typename std::map<key, val>::iterator begin = map.begin();
    std::cout << "--- STD ---\n";
    for (; begin != map.end(); begin++)
        std::cout << "first: " << begin->first << " second: " << begin->second << std::endl;
}

template<typename key, typename val>
void ft_print(typename ft::map<key, val> map)
{
    typename ft::map<key, val>::iterator begin = map.begin();
    std::cout << "--- FT ---\n";
    for (; begin != map.end(); begin++)
        std::cout << "first: " << begin->first << " second: " << begin->second << std::endl;   
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

    std::cout << "********* constructors ********** \n";
    std::map<int, char> std_map;
    ft::map<int, char>  ft_map;

    //std_map[0] = 'a';
    //ft_map[0] = 'a';

    /*std::map<int, char>::iterator std_iter = std_map.end();
    ft::map<int, char>::iterator ft_iter = ft_map.end();

    std::cout << "**** end() ****" << std::endl;
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


    //std_map.insert(std::map<int, char>::value_type(1, 'c'));
    ft_map.insert(ft::map<int, char>::value_type(1, 'c'));
    //std_map[2] = 'b';
    //ft_map[2] = 'b';
    //ft_print(ft_map);
    //std_print(std_map);

    /*ft::Node<ft::pair<int, std::string> > test;
    ft::pair<int, std::string> totest = ft::make_pair('3', "thisisatest");
    test.data = totest;
    ft::Node<ft::pair<int, std::string> >::node_ptr ptr = &ft::Node<ft::pair<int, std::string> >::nil;
    if (test != ft::Node<ft::pair<int, std::string> >::nil)
        std::cout << "test ok\n";
    if (ptr == &ft::Node<ft::pair<int, std::string> >::nil)
        std::cout << "test 2 ok\n";*/

}