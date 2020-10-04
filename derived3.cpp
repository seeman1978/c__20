//
// Created by zhaoyue on 2020/9/28.
//

#include <iostream>

class BBB{
public:
    explicit BBB(int k): m_k{k}{

    }
    BBB(int i, int j, int k):m_i{i}, m_j{j}{
        BBB{k};
        std::cout << "class BBB creator " << std::endl;
    }
private:
    int m_k, m_i, m_j;
};

int main(){
    BBB bbb(1, 2, 3);
}


