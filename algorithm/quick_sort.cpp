#include <vector>
#include <iostream>

//
// Created by 王强 on 2021/5/17.
//
template<typename ForwardIterator>
void quick_sort(ForwardIterator first, ForwardIterator last){
    if(first == last){
        return;
    }
    auto pivot = *first;

    ForwardIterator begin=first, end=last;
    while(begin!=end){
        while (begin!=end && *(end) >= pivot){// 从右向左找第一个小于pivot的数
            end = std::prev(end, 1);
        }
        if (begin != end){
            *begin = *end;
            begin = std::next(begin, 1);
        }
        while(begin!=end && *begin<pivot){// 从左向右找第一个大于等于pivot的数
            ++begin;
        }
        if (begin != end){
            *end = *begin;
            end = std::prev(end, 1);
        }
    }
    *begin = pivot;

    quick_sort(first, begin);

    quick_sort(std::next(begin, 1), last);
}

int main(){
    std::vector<int> vec{2,6,8,0,9,1,4,6,5,7,8,8,1,1,3,2,4,8,2,6,5,3,2,1,9,0};
    //std::vector<int> vec{8,9,4,6,5};
    quick_sort(vec.begin(), std::prev(vec.end(),1));

    std::cout << "data is: " << std::endl;
    for_each(vec.begin(), vec.end(), [](auto n) {std::cout << n << " "; });
    std::cout << std::endl;
}