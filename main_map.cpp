#include "map.hpp"
#include "test.hpp"
#include <iostream>
#include <map>

template<class key, class val>
void std_print(std::map<key, val>::iterator begin, std::map<int, char>::iterator end )
{
    std::cout << "--- STD ---\n";
    for (; begin != end; begin++)
        std::cout << "first: " << begin->first << "second: " << end->second << std::endl;
}

void ft_print(ft::)

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

    std_map[1] = 'a';
    ft_map[1] = 'a';

    std::map<int, char>::iterator std_iter = std_map.end();
    ft::map<int, char>::iterator ft_iter = ft_map.end();

    std::cout << "**** end() ****" << std::endl;
    std::cout << "FT -> first: " << ft_iter->first << ", ft seccond: " << ft_iter->second << std::endl;
    std::cout << "STD -> first: " << std_iter->first << ", std second: " << std_iter->second << std::endl;
    std::cout << std::endl;

    std_iter = std_map.begin();
    ft_iter = ft_map.begin();
    /*std_iter = std_map.end();
    ft_iter = ft_map.end();*/

    std::cout << "--- begin() ---" << std::endl;
    std::cout << "FT -> first: " << ft_iter->first << ", ft seccond: " << ft_iter->second << std::endl;
    std::cout << "STD -> first: " << std_iter->first << ", std second: " << std_iter->second << std::endl;
    std::cout << std::endl;

    std::cout << "--- end() ---" << std::endl;
    ft::map<int, char>::iterator ft_iter_end = ft_map.end();
    std::map<int, char>::iterator std_iter_end = std_map.end();

    std::cout << "ft: " << ft_iter_end->first << std::endl;
    std::cout << "std: " << std_iter_end->first << std::endl;



}