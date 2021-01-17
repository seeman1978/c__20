//
// Created by wq on 2021/1/17.
//

#include <iostream>

int main(){
    using namespace std;
    cout << "true in German: " << use_facet<numpunct<char>>(locale("de_DE")).truename();
    cout << "true in Chinese: " << use_facet<numpunct<char>>(locale("zh_CN")).truename();


}