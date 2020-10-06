//
// Created by 王强 on 2020/10/6.
//

#include <iostream>
#include <vector>

template<typename T>
void f(const T& var){
    T temp = var + 1.0;
    std::cout << temp << std::endl;
}

template<typename C, typename T>
T get(C& c, int n)
{
    return c[n];
}

template<typename T, typename C>
T get2(C& c, int n)
{
    return c[n];
}

int main(){
    f(7);   //推断类型int
    f<double>(7.0);   //显示指定类型

    std::vector<int> vec{1,2,3};
    //int i = get<std::vector<int> >(vec, 1); //不能推断模版参数T,因为函数返回值的类型不能推断
    int i = get2<int>(vec, 1);
    std::cout << i << std::endl;
}