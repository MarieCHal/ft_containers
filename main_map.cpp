#include "map.hpp"
#include "test.hpp"
#include <iostream>

//namespace ft {}
//using namespace ft;

int main(void)
{
    ft::Node<ft::pair<int, std::string> > test;

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
    /*try {
        testMap.insert(content);
    }
    catch (){

    }*/
}