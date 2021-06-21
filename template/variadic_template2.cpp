//
// Created by wq on 2021/6/22.
// sizeof...

#include <cassert>
#include <iostream>

template<class... A> void Print(A... arg){
    //assert(false);
}

void Print(int a1, int a2, int a3, int a4, int a5, int a6){
    std::cout << a1 << ", " << a2 << ", " << a3 << ", " << a4 << ", " << a5 << ", " << a6 << '\n';
}

template<class... A> int vaargs(A... args){
    int size = sizeof...(A);
    switch (size) {
        case 0:
            Print(99, 99, 99, 99, 99, 99);
            break;
        case 1:
            Print(99, 99, args..., 99, 99, 99);
            break;
        case 2:
            Print(99, 99, args..., 99, 99);
            break;
        case 3:
            Print(args..., 99, 99, 99);
            break;
        case 4:
            Print(99, args..., 99);
            break;
        case 5:
            Print(99, args...);
        case 6:
            Print(args...);
            break;
        default:
            Print(0, 0, 0, 0, 0, 0);
    }
    return size;
}

int main(){
    vaargs();
    vaargs(1);
    vaargs(1, 2);
    vaargs(1, 2, 3);
    vaargs(1, 2, 3, 4);
    vaargs(1, 2, 3, 4, 5);
    vaargs(1, 2, 3, 4, 5, 6);
    vaargs(1, 2, 3, 4, 5, 6, 7);
}