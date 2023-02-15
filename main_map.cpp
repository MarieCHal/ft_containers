#include "map.hpp"
#include "test.hpp"
#include <iostream>

//namespace ft {}
//using namespace ft;

int main(void)
{
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
    if (test2 == test2.nil_function())
    {
        std::cout << "test nil ok " << std::endl;
    }

    test = test.nil_function();
    ft::Node<ft::pair<int, std::string> >* pointer = NULL;
    if (pointer != &test)
        std::cout << "pointer test ok\n" ;
    std::cout << "\n------------\n" ;
    ft::map<int, std::string> testMap;
    ft::pair<int, std::string> insertInMap = ft::make_pair(1, "tesssst");
    testMap.insert(insertInMap);
    insertInMap = ft::make_pair(1, "tesssst2");
    testMap.insert(insertInMap);
    std::cout << &testMap.begin() << std::endl;

}