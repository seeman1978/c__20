//
// Created by zhaoyue on 2020/10/21.
//

#include <vector>
#include <iostream>

int main(){
    using namespace std;
    vector<int> v1;
    //vector<int>::iterator Iter;

    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);

    cout << "v1 = ";
    for(auto x : v1){
        cout << " " << x;
    }
    cout << '\n';

    // initialize a vector of vectors by moving v1
    vector<vector<int>> vv1;
    vv1.emplace(vv1.begin(), move(v1));
    vv1.emplace(vv1.begin(), move(v1));
    int i = 0;
    for(const auto& var1 : vv1){
        cout << "vv1[" << i << "]";
        for(const auto& var2: var1)
        {
            cout << " " << var2;
        }
        cout << '\n';
        ++i;
    }
}