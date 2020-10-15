//
// Created by zhaoyue on 2020/10/15.
//

#include <iostream>

void print(){

}

template<typename T, typename... Types>
void print(const T& firstArg, const Types&... args){
    std::cout << std::boolalpha << firstArg << std::endl;
    print(args...);
}
int main(){
    bool b = false;
    print(7.5, "hello", std::bitset<16>(377), 42, b);
}
