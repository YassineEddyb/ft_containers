#include <iostream>
#include <vector>
#include "vector.hpp"

int main () {
    int arr[10] = {2, 1, 6, 7, 4, 9, 0, 3, 5, 8};
    ft::vector<int> vec(arr, arr + 10);
    std::vector<int> vec2(arr, arr + 10);

    // for (int i = 0; i < 10; i++)
        std::cout << *vec.erase(vec.begin() + 2) << " ";
    std::cout << std::endl;
    // for (int i = 0; i < 10; i++)
        std::cout << *vec2.erase(vec2.begin() + 2) << " ";
    std::cout << std::endl;
    

    std::cout << vec.size() << std::endl;
    std::cout << vec2.size() << std::endl;
}