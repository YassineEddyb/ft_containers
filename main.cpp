#include "vector.hpp"
// #include <iterator>
#include <iostream>
#include <vector>

void print_vec(std::vector<int> vec) {
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

int main () {
    int arr[10] = {2, 1, 6, 7, 4, 9, 0, 3, 5, 8};
    ft::vector<int> vec(arr, arr + 10);
    std::vector<int> vec2(arr, arr + 10);


    std::cout << *vec.insert(vec.begin() + 1, 10) << std::endl;
    std::cout << *vec2.insert(vec2.begin() + 1, 10) << std::endl;

    vec.print();
    print_vec(vec2);

    std::cout << vec.size() << " " << vec2.capacity() << std::endl;
    std::cout << vec2.size() << " " << vec2.capacity() << std::endl;


    // std::cout << *vec.erase(vec.begin() + 2, vec.begin() + 6) << std::endl;
    // std::cout << *vec2.erase(vec2.begin() + 2, vec2.begin() + 6) << std::endl;
    // vec.print();
    // print_vec(vec2);
    // std::cout << vec.size() << std::endl;
    // std::cout << vec2.size() << std::endl;

    // vec.resize(11);
    // std::cout << vec.size() << std::endl;
    // std::cout << vec.capacity() << std::endl;
    // vec.print();

    // vec.reserve(15);
    // vec.pop_back();
    // vec.pop_back();
    // vec.pop_back();
    // vec.push_back(10);
    // vec.push_back(11);
    // vec.push_back(12);
    // std::cout << vec.size() << std::endl;
    // std::cout << vec.capacity() << std::endl;



    // iterator tests
        // ft::vector<int>::iterator begin = vec.begin();
        // ft::vector<int>::iterator end = vec.end();
        // std::cout << begin[4] << std::endl;
        // ft::vector<int>::iterator start = begin;
        // ft::vector<int>::iterator last = end;
        // std::cout << *start << std::endl;
        // std::cout << *last << std::endl;

        // start++;
        // last--;
        // std::cout << *start << std::endl;
        // std::cout << *last << std::endl;

        // std::cout << *--start << std::endl;
        // std::cout << *++last << std::endl;

        // *start++;
        // *end--;
        // std::cout << *start << std::endl;
        // std::cout << *last << std::endl;

    // vector tests
        // std::cout << vec.capacity() << std::endl;
        // std::cout << vec.size() << std::endl;
        // std::cout << vec.max_size() << std::endl;
        // std::cout << vec.empty() << std::endl;

        // std::cout << vec.front() << std::endl;
        // std::cout << vec.back() << std::endl;
        // std::cout << vec[4] << std::endl;
        // std::cout << vec.data() << std::endl; Not working
        // vec.clear();
        // ft::vector<int>::iterator it = vec.begin();

        // std::cout << *it << std::endl;
        // std::cout << vec.size() << std::endl;
        // std::cout << vec.capacity() << std::endl;
}