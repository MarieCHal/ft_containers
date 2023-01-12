
#include <iostream>
#include <memory>


int main(void)
{
    std::allocator<char>::pointer p;
    char s = 'S'; 
    p = &s;
    std::cout << "a: " << p << " add: " << &p << std::endl;
    p += 5;
    std::cout << "a++: " << p << " add: " << &p << std::endl;
}