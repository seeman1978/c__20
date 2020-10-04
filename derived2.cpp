//
// Created by zhaoyue on 2020/9/28.
//

#include <iostream>

class B{
public:
    B(int i):m_i{i}{
        std::cout << "class B creator " << std::endl;
    }

private:
    int m_i;
};

class BB: public B{
public:
    BB(int i, int j):B{i}, m_j{j}{
        std::cout << "class BB creator " << std::endl;
    }
private:
    int m_j;
};

class BBB: public BB{
public:
    BBB(int i, int j, int k):BB{i, j}, m_k{k}{
        std::cout << "class BBB creator " << std::endl;
    }
private:
    const int m_k;
};

int main(){
    BBB bbb(1, 2, 3);
}


