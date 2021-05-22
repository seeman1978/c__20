//
// Created by wq on 2021/5/19.
//

//
// Created by 王强 on 2021/5/17.
//

#include <vector>
#include <iostream>

//
// Created by 王强 on 2021/5/17.
//

void quick_sort(int arr[], int first, int last){
    if(first < last){
        int pos = first+(last-first)/2;
        int x = arr[pos];

        int begin=first, end=last;
        while(begin<end){
            while (begin<end && arr[end] >= x){// 从右向左找第一个小于pivot的数
                --end;
                if (end == pos){    //end不要跨过pos
                    break;
                }
            }
            if (begin < end){
                std::swap(arr[pos], arr[end]);
                pos = end;
            }
            while(begin<last && arr[begin]<x){// 从左向右找第一个大于等于pivot的数
                ++begin;
                if (begin == end){//begin不要跨过pos
                    break;
                }
            }
            if (begin < last){
                std::swap(arr[pos], arr[begin]);
                pos = begin;
            }
        }

        quick_sort(arr, first, begin-1);

        quick_sort(arr, begin+1, last);
    }
}

int main(){
    int vec[]{2,6,8,0,9,1,4,6,5,7,8,8,1,1,3,2,4,8,2,6,5,3,2,1,9,0};
    //int vec[]{2,6,8,0,9,1};
    quick_sort(vec, 0, sizeof(vec) / sizeof(vec[0])-1);

    std::cout << "data is: " << std::endl;
    std::for_each(std::begin(vec), std::end(vec), [](auto n) {std::cout << n << " "; });
    std::cout << std::endl;
}