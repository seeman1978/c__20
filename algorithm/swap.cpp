//
// Created by 王强 on 2020/10/25.
//

#include <vector>
#include <list>
#include <iostream>
#include <random>

template <typename ForwardIt>
void selection_sort(ForwardIt begin, ForwardIt end){
    for (ForwardIt i=begin; i!=end; ++i){
        std::iter_swap(i, std::min_element(i, end));
    }
}

int main(){
    using namespace std;
    {
        vector<int> v{1,2,3,4,5};
        list<int> l{-1,-2,-3,-4,-5};
        swap_ranges(v.begin()+1, v.begin()+3, l.begin());
        for (int n:v){
            cout << n << ' ';
        }
        cout << '\n';
        for (int n:l){
            cout << n << ' ';
        }
        cout << '\n';
    }
    {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dist(-10, 10);
        vector<int> v;
        generate_n(back_inserter(v), 20, bind(dist, gen));

        cout << "Before sort: ";
        for (auto e:v){
            cout << e << " ";
        }
        selection_sort(v.begin(), v.end());
        cout << "\nAfter sort: ";
        for (auto e:v){
            cout << e << " ";
        }
        cout << '\n';
    }
}