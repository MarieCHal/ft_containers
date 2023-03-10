#include <vector>
#include <map>
#include <stack>
#include <iostream>

template<typename key, typename val>
void std_print_map(typename std::map<key, val> map, std::string name)
{
    typename std::map<key, val>::iterator begin = map.begin();
    std::cout << "--- content of : " << name << " ---\n";
    for (; begin != map.end(); begin++)
        std::cout << "first: " << begin->first << " second: " << begin->second << std::endl;   
    std::cout << "map size: " << map.size() << std::endl;
}

template<class T>
void std_print_vector(std::vector<T> vector, std::string name) 
{
    std::cout << "--- content of : " << name << " ---\n";
    for (size_t i = 0; i < vector.size() ; i++)
        std::cout << vector[i] << std::endl;
    std::cout << "size: " << vector.size() << std::endl;
    std::cout << "capcity: " << vector.capacity() << std::endl << std::endl;
}

int main(void)
{

    std::cout << "* * * * * * * * * * * * * * * * * * * * \n";
    std::cout << "*                                     * \n";
    std::cout << "*             VECTOR                  * \n";
    std::cout << "*                                     * \n";
    std::cout << "* * * * * * * * * * * * * * * * * * * * \n\n˙";
    std::cout << " ===================================== \n";
    std::cout << " =          constructors             =\n";
    std::cout << " ===================================== \n\n";

    std::cout << "      initialized constructor      \n";
    std::vector<char> std_vector(3, 'c');
    std_print_vector(std_vector, "vector");
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      copy constructor      \n";
    std::vector<char> std_vector_copy(std_vector);
    std_print_vector(std_vector, "vector copy");
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "       constructor with iterator range    \n";
    std::vector<char>::iterator it_begin = std_vector.begin();
    std::vector<char>::iterator it_end = std_vector.end();
    std::vector<char> std_vector_it(it_begin, it_end);
    std_print_vector(std_vector_it, "vector iterator range");
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << " ===================================== \n";
    std::cout << " =          member functions         =\n";
    std::cout << " ===================================== \n\n";
    std::cout << "      operator =       \n";
    std::vector<char> std_vector_equal;
    std_vector_equal = std_vector;
    std_print_vector(std_vector_equal, "vector equal");
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      assign(size, value_type)      \n";
    std_print_vector(std_vector, "before");
    std_vector.assign(4, 'g');
    std_print_vector(std_vector, "after assigning 4 times 'g' ");
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      assign(it, it)      \n";
    std_vector_copy.push_back('1');
    std_vector_copy.push_back('2');
    std_vector_copy.push_back('3');
    std_vector_copy.push_back('4');
    std_vector.assign(std_vector_copy.begin(), std_vector_copy.end());
    std_print_vector(std_vector, "after assigning ");
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std_vector.push_back('o');
    std_vector.push_back('l');
    std_vector.push_back('l');
    std_vector.push_back('a');
    std_print_vector(std_vector, "vector");
    std::cout << "      at()     \n";
    std::cout << "vector at pos 3: " << std_vector.at(3) << std::endl;
    std::cout << "vector at pos 3: " << std_vector.at(6) << std::endl;
    std::cout << "vector at pos 3: " << std_vector.at(9) << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      operator[]     \n";
    std::cout << "vector at pos 3: " << std_vector[3] << std::endl;
    std::cout << "vector at pos 3: " << std_vector[6] << std::endl;
    std::cout << "vector at pos 3: " << std_vector[9] << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      front()     \n";
    std::cout << "vector at front pos : " << std_vector.front() << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      const front()     \n";
    std::vector<char>::const_reference refFront = std_vector.front();
    std::cout << "vector at const front pos : " << refFront << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      back()     \n";
    std::cout << "vector at back pos : " << std_vector.back() << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      const back()     \n";
    std::vector<char>::const_reference refBack = std_vector.back();
    std::cout << "vector at back pos : " << refBack << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      data()     \n";
    std::vector<char>::pointer data = std_vector.data();
    std::cout << "vector data: " << data << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "     const data()     \n";
    std::vector<char>::const_pointer dataConst = std_vector.data();
    std::cout << "vector data: " << dataConst << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    


    std::cout << " ===================================== \n";
    std::cout << " =          iterators                =\n";
    std::cout << " ===================================== \n\n";

    std::cout << "      begin()     \n";
    std::vector<char>::iterator beg = std_vector.begin();
    std::cout << "vector at iterator begin : " << *(beg) << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      const begin()     \n";
    std::vector<char>::const_iterator const_beg = std_vector.begin();
    std::cout << "vector at iterator begin : " << *(const_beg) << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      end()     \n";
    std::vector<char>::iterator end = std_vector.begin();
    std::cout << "vector at iterator end++ : " << *(end)++ << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      const end()     \n";
    std::vector<char>::const_iterator const_end = std_vector.begin();
    std::cout << "vector at iterator end++ : " << *(const_end)++ << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      rbegin()     \n";
    std::vector<char>::reverse_iterator rbeg = std_vector.rbegin();
    std::cout << "vector at iterator rbeg : " << *(rbeg)++ << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      const rbegin()     \n";
    std::vector<char>::const_reverse_iterator const_rbeg = std_vector.rbegin();
    std::cout << "vector at iterator rbeg : " << *(const_rbeg)++ << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      rend()     \n";
    std::vector<char>::reverse_iterator rend = std_vector.rend();
    std::cout << "vector at iterator rend : " << *(rend) - 2 << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      const rend()     \n";
    std::vector<char>::const_reverse_iterator const_rend = std_vector.rend();
    std::cout << "vector at iterator rend : " << *(const_rend) - 2 << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";


    std::cout << " ===================================== \n";
    std::cout << " =          capacity                 =\n";
    std::cout << " ===================================== \n\n";
    std::cout << "      empty()     \n";
    std::cout << "vector is empty: " << std_vector.empty();
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      size()     \n";
    std::cout << "vector size: " << std_vector.size();
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      reserve() / capcity()    \n";
    std::cout << "vector capacity before: " << std_vector.capacity();
    std_vector.reserve(4);
    std::cout << "vector capacity after reserving 4: " << std_vector.capacity();
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      clear()    \n";
    std_vector.clear();
    std_print_vector(std_vector, "vector cleared");
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      insert(iter, iter)    \n";
    std::vector<char>::iterator iter_beg = std_vector.begin();
    std_vector.insert(iter_beg, std_vector_copy.begin(), std_vector_copy.end());
    std_print_vector(std_vector, "vector after re-inserting");
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      insert(pos, n, val)    \n";
    std_vector.insert(std_vector.begin(), 3, 'p');
    std_print_vector(std_vector, "vector after inserting 3 times 'p' ");
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      insert(pos, val)    \n";
    std_vector.insert(std_vector.begin() + 2, 'x');
    std_print_vector(std_vector, "vector after inserting x ");
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      erase(pos)    \n";
    std_vector.erase(std_vector.begin());
    std_print_vector(std_vector, "vector after ersase" ) ;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      erase()    \n";
    std::vector<char>::iterator it_erase = std_vector.begin();
    std::vector<char>::iterator it2_erase(it_erase);
    it_erase ++;
    std_vector.erase(it2_erase, it_erase + 2);
    std_print_vector(std_vector, "vector after erase");
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      puch_back()    \n";
    std_print_vector(std_vector, "vector before push back" ) ;
    std_vector.push_back('1');
    std_vector.push_back('2');
    std_vector.push_back('3');
    std_print_vector(std_vector, "vector after push back" ) ;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      pop_back()    \n";
    std_print_vector(std_vector, "vector before pop back" ) ;
    std_vector.pop_back();
    std_vector.pop_back();
    std_print_vector(std_vector, "vector after pop back" ) ;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      resize()    \n";
    std::cout << "vector capacity before resize 2: " << std_vector.capacity() << std::endl;
    std_vector.resize(2, 'r');
    std_print_vector(std_vector, "vector after resize 2");
    std::cout << "vector capacity before resize 100: " << std_vector.capacity() << std::endl;
    std_print_vector(std_vector, "vector after resize 100");
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::vector<char> std_vect2;
    std_vect2.push_back('l');
    std_vect2.push_back('a');
    std_vect2.push_back('l');
    std_vect2.push_back('a');

    std::cout << "      swap()    \n";
    std_print_vector(std_vector, "vector 1");
    std_print_vector(std_vect2, "vector 2");
    std_vector.swap(std_vect2);
    std_print_vector(std_vector, "vector 1");
    std_print_vector(std_vect2, "vector 2");

    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << " ===================================== \n";
    std::cout << " =          non member functions     =\n";
    std::cout << " ===================================== \n\n";

    std::vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(5);
    v1.push_back(6);

    std::vector<int> v2;
    v2.push_back(1);
    v2.push_back(22);
    v2.push_back(3);
    v2.push_back(43);
    v2.push_back(55);
    v2.push_back(66);
    v2.push_back(24);
    v2.push_back(3);

    std::vector<int> v3;
    v3.push_back(1);
    v3.push_back(2);
    v3.push_back(3);
    v3.push_back(4);
    v3.push_back(6);
    v3.push_back(5);

    std_print_vector(v1, "vector 1");
    std_print_vector(v2, "vector 2");
    std_print_vector(v3, "vector 3");
    std::cout << "      operator==()    \n";
    std::cout << "v2 == v1 ? :" << (v2 == v1) << std::endl;
    std::cout << "v3 == v1 ? :" << (v3 == v1) << std::endl;
    std::cout << "v2 == v3 ? :" << (v2 == v3) << std::endl;
    std::vector<int> v1_copy(v1);
    std::cout << "v1 == v1 copy ? :" << (v1 == v1_copy) << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      operator!=()    \n";
    std::cout << "v2 != v1 ? :" << (v2 != v1) << std::endl;
    std::cout << "v3 != v1 ? :" << (v3 != v1) << std::endl;
    std::cout << "v2 != v3 ? :" << (v2 != v3) << std::endl;
    std::cout << "v1 != v1 copy ? :" << (v1 != v1_copy) << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      operator<()    \n";
    std::cout << "v2 < v1 ? :" << (v2 < v1) << std::endl;
    std::cout << "v3 < v1 ? :" << (v3 < v1) << std::endl;
    std::cout << "v2 < v3 ? :" << (v2 < v3) << std::endl;
    std::cout << "v1 < v1 copy ? :" << (v1 < v1_copy) << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      operato>()    \n";
    std::cout << "v2 > v1 ? :" << (v2 > v1) << std::endl;
    std::cout << "v3 > v1 ? :" << (v3 > v1) << std::endl;
    std::cout << "v2 > v3 ? :" << (v2 > v3) << std::endl;
    std::cout << "v1 > v1 copy ? :" << (v1 > v1_copy) << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      operator<=()    \n";
    std::cout << "v2 <= v1 ? :" << (v2 <= v1) << std::endl;
    std::cout << "v3 <= v1 ? :" << (v3 <= v1) << std::endl;
    std::cout << "v2 <= v3 ? :" << (v2 <= v3) << std::endl;
    std::cout << "v1 <= v1 copy ? :" << (v1 <= v1_copy) << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      operator>=()    \n";
    std::cout << "v2 >= v1 ? :" << (v2 >= v1) << std::endl;
    std::cout << "v3 >= v1 ? :" << (v3 >= v1) << std::endl;
    std::cout << "v2 >= v3 ? :" << (v2 >= v3) << std::endl;
    std::cout << "v1 >= v1 copy ? :" << (v1 >= v1_copy) << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      swap(vect1, vect2)    \n";
    std_print_vector(v1, "v1 before swap");
    std_print_vector(v2, "v2 before swap");
    std::swap(v1, v2);
    std_print_vector(v1, "v1 after swap");
    std_print_vector(v2, "v2 after swap");
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";
    

    std::cout << "* * * * * * * * * * * * * * * * * * * * \n";
    std::cout << "*                                     * \n";
    std::cout << "*             STACK                   * \n";
    std::cout << "*                                     * \n";
    std::cout << "* * * * * * * * * * * * * * * * * * * * \n\n˙";


    std::stack<std::string> s;
    std::stack<std::string> s1(s);
    std::stack<std::string> s2(s);
    std::stack<std::string> s3(s);
    s3.push("heyoooo");

    std::cout << "    push/top/pop      \n";
    s.push("je suis la premiere");
    s.push("je suis la deuxieme");
    s.push("Jesuiiis la troiisieme");
    s.push("JeSuiiIsLaaaQuatriiieeemmeee");
    s.push("jaSoisIaCipiame");
    s.push("jsslsm");
    s.push("haayayaya");

    while (s.empty() == false)
    {
        std::cout << "this is the top of the stack: " << s.top() << std::endl;
        s.pop();
    }
    std::cout << "    stack empty   \n" ;

    std::cout << "      operator==()    \n";
    std::cout << "s2 == s1 ? :" << (s2 == s1) << std::endl;
    std::cout << "s3 == s1 ? :" << (s3 == s1) << std::endl;
    std::cout << "s2 == s3 ? :" << (s2 == s3) << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      operator!=()    \n";
    std::cout << "s2 != s1 ? :" << (s2 != s1) << std::endl;
    std::cout << "s3 != s1 ? :" << (s3 != s1) << std::endl;
    std::cout << "s2 != s3 ? :" << (s2 != s3) << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      operator<()    \n";
    std::cout << "s2 < s1 ? :" << (s2 < s1) << std::endl;
    std::cout << "s3 < s1 ? :" << (s3 < s1) << std::endl;
    std::cout << "s2 < s3 ? :" << (s2 < s3) << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      operato>()    \n";
    std::cout << "s2 > s1 ? :" << (s2 > s1) << std::endl;
    std::cout << "s3 > s1 ? :" << (s3 > s1) << std::endl;
    std::cout << "s2 > s3 ? :" << (s2 > s3) << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      operator<=()    \n";
    std::cout << "s2 <= s1 ? :" << (s2 <= s1) << std::endl;
    std::cout << "s3 <= s1 ? :" << (s3 <= s1) << std::endl;
    std::cout << "s2 <= s3 ? :" << (s2 <= s3) << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      operator>=()    \n";
    std::cout << "s2 >= s1 ? :" << (s2 >= s1) << std::endl;
    std::cout << "s3 >= s1 ? :" << (s3 >= s1) << std::endl;
    std::cout << "s2 >= s3 ? :" << (s2 >= s3) << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";


    std::cout << "* * * * * * * * * * * * * * * * * * * * \n";
    std::cout << "*                                     * \n";
    std::cout << "*             MAP                     * \n";
    std::cout << "*                                     * \n";
    std::cout << "* * * * * * * * * * * * * * * * * * * * \n\n˙";
    std::cout << " ===================================== \n\n";
    std::cout << " =          constructors             =\n";
    std::cout << " ===================================== \n\n";
    std::map<int, char>  std_map;

    std_map[0] = 'a';
    std_map[1] = 'z';
    std_map[2] = 'b';


    std_print_map(std_map, "map");
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      copy constructor      \n";
    std::map<int, char> std_map_copy(std_map);
    std_print_map(std_map, "map");
    std_print_map(std_map_copy, "map_copy");
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      iterator constructor      \n";
    std::map<int, char>::iterator iter_begin = std_map.begin();
    std::map<int, char>::iterator iter_end = std_map.end();
    std::map<int, char> std_map_iter(iter_begin, iter_end);
    std_print_map(std_map, "map");
    std_print_map(std_map_iter, "map_iter");
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
    std_print_map(std_map, "map");
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
    std_iter--;
    std::cout << "map at end()--: " << std_iter->first << ", " << std_iter->second << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      rbegin() -> reverse iterator     \n";
    std::map<int, char>::reverse_iterator std_iter_rev = std_map.rbegin();
    std::cout << "map at rbegin(): " << std_iter_rev->first << ", " << std_iter_rev->second << std::endl << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      const rbegin() -> const reverse iterator     \n";
    std::map<int, char>::const_reverse_iterator const_std_iter_rev = std_map.rbegin();
    std::cout << "map at const begin(): " << const_std_iter_rev->first << ", " << const_std_iter_rev->second << std::endl << std::endl;
    const_std_iter_rev++;
    std::cout << "map at const begin() ++ : " << const_std_iter_rev->first << ", " << const_std_iter_rev->second << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      rend() -> reverse iterator     \n";
    std_iter_rev = std_map.rend();
    std_iter_rev--;
    std::cout << "map at rend(): " << std_iter_rev->first << ", " << std_iter_rev->second << std::endl;
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      const rend() -> const reverse iterator     \n";
    const_std_iter_rev = std_map.rend();
    const_std_iter_rev--;
    std::cout << "map at const rend(): " << const_std_iter_rev->first << ", " << const_std_iter_rev->second << std::endl;
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
    std_print_map(std_map_copy, "before");
    std_map_copy.clear();
    std_print_map(std_map_copy, "after");
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      insert(val)      \n";
    std_print_map(std_map, "before");
    std::pair<int, char> pair = std::make_pair(8, 'f');
    std_map.insert(pair);
    std_print_map(std_map, "after");
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      insert(it1, it2)      \n";
    std_print_map(std_map, "before inserting [3, p], [11, q], [56, l] ");
    std::map<int, char>  other;
    other[3] = 'p';
    other[11] = 'q'; 
    other[56] = 'l';
    std_map.insert(other.begin(), other.end());
    std_print_map(std_map, "after");
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      erase(key)      \n";
    std_print_map(std_map, "before");
    std::cout << " erasing element at pos: begin++ (z) \n";
    std_iter = std_map.begin();
    std_iter++;
    std_map.erase(std_iter);
    std_print_map(std_map, "after");
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";

    std::cout << "      erase(iter1, iter2)      \n";
    std_print_map(std_map, "before");
    std::cout << " erasing from pos 2 to 11\n" ;
    std::map<int, char>::iterator m_begin = std_map.find(2);
    std::map<int, char>::iterator m_end = std_map.find(11);
    std_map.erase(m_begin, m_end);
    std_print_map(std_map, "after");
    std::cout << "\n . . . . . . . . . . . . . . . .\n\n";


    std::cout << "      swap(map)      \n";
    std_print_map(other, "map1 before ");
    std_print_map(std_map, "map2 before ");
    std_map.swap(other);
    std_print_map(other, "map1 after ");
    std_print_map(std_map, "map2 after ");
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
    std_print_map(std_map, "std_map");
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