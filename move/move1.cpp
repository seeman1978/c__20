//
// Created by wq on 22-8-4.
//

#include <iostream>

void f1(int i){
    int n = std::move(i);
    std::cout << n << "\n";
}

void f2(int i){
    int n = std::move(i);
    std::cout << n << "\n";
}

int main(){
    int j = 9;
    f1(j);
    std::cout << "from main:" << j << "\n";
    f2(j);

}