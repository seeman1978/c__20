#include <list>
#include <numeric>
#include <vector>
#include <random>
#include <iostream>

//
// Created by zhaoyue on 2020/11/19.
//
int main(){
    std::list<int> l(10);
    std::iota(l.begin(), l.end(), -4);// sequentially increasing values,*(d_first)   = value;*(d_first+1) = ++value;
    std::vector<std::reference_wrapper<int>> v(l.begin(), l.end());

    // can't use shuffle on a list (requires random access), but can use it on a vector
    std::shuffle(v.begin(), v.end(), std::mt19937{std::random_device{}()});
    std::cout << "Contents of the list: ";
    for (auto n : l){
        std::cout << n << ' ';
    }

    std::cout << "\nContents of the list, as seen through a shuffled vector: ";
    for (auto i : v){
        std::cout << i << ' ';
    }

    std::cout << "\n\nDoubling the values in the initial list...\n\n";
    for (auto& var : l) {
        var *= 2;
    }
    std::cout << "Contents of the list: ";
    for (auto n : l){
        std::cout << n << ' ';
    }
    std::cout << "\nContents of the list, as seen through a shuffled vector: ";
    for (int i : v){
        std::cout << i << ' ';
    }
}
