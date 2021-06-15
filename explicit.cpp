//
// Created by wq on 2021/6/15.
//

#include <iostream>

template<typename T>
class Ptr{
public:
    explicit Ptr(T* p): m_p{p}{}
    explicit operator bool() const{
        if (m_p != nullptr){
            return true;
        }
        else{
            return false;
        }
    }
private:
    T* m_p = nullptr;
};

int main(){
    int a = 9;
    Ptr<int> p{&a};
    if (p){
        std::cout << "valid pointer.\n";
    }
    else{
        std::cout << "invalid pointer.\n";
    }

    Ptr<double> pD{nullptr};
    //std::cout << p + pD << '\n';
}