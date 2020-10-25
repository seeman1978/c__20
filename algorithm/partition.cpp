//
// Created by 王强 on 2020/10/25.
//

#include <iterator>
#include <algorithm>
#include <vector>
#include <iostream>
#include <forward_list>

//p=partition(b,e,f)将满足条件f的元素至于区间[b:p)内，将其他元素至于区间[p:e)内

template <typename ForwardIt>
void quicksort(ForwardIt first, ForwardIt last){
    if (first == last){
        return;
    }
    auto pivot = *std::next(first, std::distance(first, last)/2);
    ForwardIt middle1 = std::partition(first, last, [pivot](const auto& em){return em < pivot;});
    ForwardIt middle2 = std::partition(middle1, last, [pivot](const auto& em){return pivot >= em;});
    quicksort(first, middle1);
    quicksort(middle2, last);
}

int main(){
    using namespace std;
    vector<int> v{0,1,2,3,4,5,6,7,8,9};
    cout << "original vector:\n     ";
    for (int elem : v){
        cout << elem << ' ';
    }
    auto it = std::partition(v.begin(), v.end(), [](int i){return i%2 == 0;});
    cout << "\n Partition vector:\n     ";
    copy(v.begin(), it, ostream_iterator<int>(cout, " "));
    cout << " * ";
    copy(it, v.end(), ostream_iterator<int>(cout, " "));

    forward_list<int> fl{1, 30, -4, 3, 5, -4, 1, 6, -8, 2, -5, 64, 1, 92};
    cout << "\nUnsorted list:\n     ";
    for (int n: fl){
        cout << n << ' ';
    }
    cout << '\n';
    quicksort(fl.begin(), fl.end());
    cout << "Sorted using quicksort:\n      ";
    for (int fi : fl){
        cout << fi << ' ';
    }
    cout << '\n';
}