//
// Created by wq on 2020/10/24.
//
#include <vector>
#include <iostream>

int main(){
    using namespace std;
    vector<int> v{1,2,3};
    for_each(v.begin(), v.end(), [](int& x){++x;}); //v中的每个元素
    for_each(v.begin(), v.end(), [](const int x){cout << x << ' ';});
}