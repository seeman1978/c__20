//
// Created by 王强 on 2021/5/18.
//

#include <array>
#include <c++/v1/iostream>

// 递归方式构建大根堆(len是arr的长度，index是第一个非叶子节点的下标)
template<typename T>
void adjust(T begin, T end, int index){
    int len = std::distance(begin, end);
    int left = 2*index + 1; // index的左子节点
    int right = 2*index +2; // index的右子节点
    int maxInx = index;
    if (left<len && arr[left]>)
}

template<typename T>
void heapSort(T begin, T end){
    int size = std::distance(begin, end);
    // 构建大根堆（从最后一个非叶子节点向上）
    for (int i = size/2-1; i >=0 ; --i) {
        adjust();
    }
    // 调整大根堆
    for (auto pos = end; pos != begin; --pos) {
        std::swap(*begin, *pos);    // 将当前最大的放置到数组末尾
        adjust();                   // 将未完成排序的部分继续进行堆排序
    }
}

int main(){
    std::array<int, 8> arr{8, 1, 14, 3, 21, 5, 7, 10};
    heapSort(arr.begin(), std::prev(arr.end(), 1));
    for (auto x : arr) {
        std::cout << x << ' ';
    }
}