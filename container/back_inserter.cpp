//
// Created by zhaoyue on 2020/11/19.
//

#include <vector>
#include <iostream>

int main(){
    /*{
        std::vector<int> v1{1,2,3};
        std::vector<int> v2; //EXC_BAD_ACCESS
        std::copy(v1.begin(), v1.end(), v2.begin());
        for (auto var:v2){
            std::cout << var << ' ';
        }
        std::cout << '\n';
    }*/

    {
        std::vector<int> v1{1,2,3};
        std::vector<int> v2(3);
        std::copy(v1.begin(), v1.end(), v2.begin());
        for (auto var:v2){
            std::cout << var << ' ';
        }
        std::cout << '\n';
    }

    {
        std::vector<int> v1{1,2,3};
        std::vector<int> v2;
        std::copy(v1.begin(), v1.end(), std::back_inserter(v2));
        for (auto var:v2){
            std::cout << var << ' ';
        }
        std::cout << '\n';
    }

}
