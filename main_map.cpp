#include "map.hpp"
#include "test.hpp"
#include <iostream>

//namespace ft {}
//using namespace ft;

int main(void)
{
    ft::map<int, std::string> testMap;
    ft::Node<ft::pair<int, std::string> > test;

    ft::pair<int, std::string> content(1, "coucou");
    test.data = content;
    std::cout << "content of nodes" << std::endl;
    std::cout << test.data.first << ", " << test.data.second << std::endl;

    ft::Node<ft::pair<int, std::string> > test2;
    test2 = test;
    std::cout << "copy nodes" << std::endl;
    std::cout << test2.data.first << ", " << test2.data.second << std::endl;

    std::cout << "nil comparision" << std::endl;
    if (test2 == test2.nil())
    {
        std::cout << "test nil ok " << std::endl;
    }

    std::cout << "\n------------\n" ;
    ft::pair<int, std::string> insertInMap = ft::make_pair(1, "tesssst");
    testMap.insert(insertInMap);

}