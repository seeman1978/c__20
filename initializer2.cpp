//
// Created by 王强 on 2020/9/28.
//

#include <string>
#include <iostream>

template<typename T>
class A{
public:
    A(std::initializer_list<T> l) {
        std::cout << "A constructed with a " << l.size() << "-element list\n";
    }
    A(int a, const std::string& str):a{a}, str{str}{
        std::cout << "A constructed with a str\n";
    }

    A(int a, int b):a{a}, b{b}{
        std::cout << "A constructed with a b\n";
    }
private:
    int a{8};
    int b = 9;
    //int c(7); //error
    std::string str;
};

template<typename T>
class B{
public:
    /*B(std::initializer_list<T> l) {
        std::cout << "B constructed with a " << l.size() << "-element list\n";
    }*/
    B(int a, const std::string& str):a{a}, str{str}{
        std::cout << "B constructed with a str\n";
    }

    B(int a, int b):a{a}, b{b}{
        std::cout << "B constructed with a b\n";
    }
private:
    int a{8};
    int b = 9;
    //int c(7); //error
    std::string str;
};

int main(){
    int d(10);
    //A a {11, 90}; //只有成员是public才可以按序初始化
    A a1{1, 2}; //自动推断模版类型是int
    //A a2(3, 4); //无法自动推断模版类型
    A<int> a2{3, 4};
    A<int> a3(3, 4);
    A<int> a4{5, "hello"};

    B<int> b1{1, 2};
    B<int> b2(3, 4);
}