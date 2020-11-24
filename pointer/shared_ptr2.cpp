//
// Created by zhaoyue on 2020/11/24.
//

#include <memory>
#include <iostream>

int getInt(){
    return 10;
}

void f(std::shared_ptr<std::string> pStr, int i){
    std::cout << *pStr << '\n';
}

int main(){
    f(std::make_shared<std::string>("hello"), getInt());
    //这样做，有内存泄露的风险。如果getInt函数出现异常，会导致下面的调用方式出现内存泄露。
    f(std::shared_ptr<std::string>{new std::string{"hello"}}, getInt());
}