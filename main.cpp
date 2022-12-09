
#include "vector.hpp"
#include <vector>

template < class T>
void std_print(std::vector<T> vect)
{
    size_t pos;
    pos = 0;
    while (pos < vect.size())
    {
        std::cout << vect.at(pos);
        pos++;
    }
    std::cout << std::endl;
}

// TO DO :
// print_vector to compare
// 
// fix capcity * 2
// iterator traits
// should insert just insert or move all the other values? (TEST 4)


int main(void)
{
    ft::vector<char>ft_vector (5, 'a');
    std::vector<char>std_vector (5, 'a');


    //print_vector(std_vector);
    std::cout << "FT_VECTOR: ";
    ft_vector.print_vect();
    std::cout << "STD_VECTOR" ;
    std_print(std_vector);
    std::cout << "---- TEST 1: testing pushback and pop back  and back----\n";
    std::cout << "FT_VECTOR last element after construction: " << ft_vector.back() << std::endl; 
    std::cout << "STD_VECTOR last element after construction: " << std_vector.back() << std::endl;
    std::cout << "FT_VECTOR capacity: " << ft_vector.capacity() << std::endl;
    std::cout << "STD_VECTOR capacity: " << std_vector.capacity() << std::endl;

    ft_vector.push_back('C');
    std::cout << "FT_VECTOR push back element: " << ft_vector.back() <<std::endl; 
    std::cout << "FT_VECTOR: ";
    ft_vector.print_vect();
    std_vector.push_back('C');
    std::cout << "STD_VECTOR push back element: " << std_vector.back() << std::endl; 
     std::cout << "FT_VECTOR capacity: " << ft_vector.capacity() << std::endl;
    std::cout << "STD_VECTOR capacity: " << std_vector.capacity() << std::endl;

    ft_vector.push_back('B');
    std::cout << "FT_VECTOR pop back element: " << ft_vector.back() <<std::endl; 
    std::cout << "FT_VECTOR: ";
    ft_vector.print_vect();
    std_vector.push_back('B');
    std::cout << "STD_VECTOR push back element: " << std_vector.back() << std::endl; 
     std::cout << "FT_VECTOR capacity: " << ft_vector.capacity() << std::endl;
    std::cout << "STD_VECTOR capacity: " << std_vector.capacity() << std::endl;

    ft_vector.pop_back();
    std::cout << "FT_VECTOR pop back element: " << ft_vector.back() <<std::endl; 
    std::cout << "FT_VECTOR: ";
    ft_vector.print_vect();
    std_vector.pop_back();
    std::cout << "STD_VECTOR pop back element: " << std_vector.back() << std::endl; 

    std::cout << "FT_VECTOR vector size: " << ft_vector.size() << std::endl;
    std::cout << "STD_VECTOR vector size: " << std_vector.size() << std::endl;
    std::cout << "FT_VECTOR capacity: " << ft_vector.capacity() << std::endl;
    std::cout << "STD_VECTOR capacity: " << std_vector.capacity() << std::endl;

    std::cout << "----------- TEST 2 : clear, assign & front -------------\n";
    ft_vector.clear();
    std_vector.clear();
    std::cout << "\n          * clear *          " << std::endl;
    std::cout << "FT_VECTOR after clear: " << ft_vector.front() << " size: " << ft_vector.size() << std::endl;
    std::cout << "FT_VECTOR: ";
    ft_vector.print_vect();
    std::cout << "STD_VECTOR after clear: " << std_vector.front() << " size: " << std_vector.size() << std::endl;
    std::cout << "\n          * assign *          " << std::endl;
    ft_vector.assign(3, 'p');
    std::cout << "FT_VECTOR: ";
    ft_vector.print_vect();
    std_vector.assign(3, 'p');

    std::cout << "\n----------- TEST 3 :  capacity ------------\n";
    std::cout << "FT_VECTOR capacity: " << ft_vector.capacity() << std::endl;
    std::cout << "STD_VECTOR capacity: " << std_vector.capacity() << std::endl;
    std::cout << "FT_VECTOR size: " << ft_vector.size() << std::endl;
    std::cout << "STD_VECTOR size: " << std_vector.size() << std::endl;
    std::cout << "FT_VECTOR back: " << ft_vector.back() << std::endl;
    std::cout << "STD_VECTOR back: " << std_vector.back() << std::endl;
    std::cout << "FT_VECTOR front: " << ft_vector.front() << std::endl;
    std::cout << "STD_VECTOR front: " << std_vector.front() << std::endl;

    
    std::cout << "----------- TEST 4 : reserve ------------\n";
    std::cout << "\n          * reserve *          " << std::endl;
    ft_vector.reserve(13);
    std_vector.reserve(13);
    std::cout << "FT_VECTOR capacity: " << ft_vector.capacity() << std::endl;
    std::cout << "STD_VECTOR capacity: " << std_vector.capacity() << std::endl;
    ft::vector<char>::iterator ft_it = ft_vector.begin();
    std::vector<char>::iterator std_it = std_vector.begin();
    ft_vector.insert(ft_it, 's');
    std_vector.insert(std_it, 's');
    std::cout << "FT_VECTOR: ";
    ft_vector.print_vect();
    std::cout << "STD_VECTOR: " << std_vector.front();

    //std::cout << "ft_vector size: " << ft_vector.size() << std::endl;
    //std::cout << "----------- TEST 3 : ft_iterators ------------\n";
   // std::cout << "----------- TEST 2 : push_back ------------\n";
   // std::cout << "----------- TEST 2 : push_back ------------\n";
}