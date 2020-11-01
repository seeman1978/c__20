//
// Created by 王强 on 2020/10/6.
//

#include <iostream>
#include <vector>
#include <string>

//类型作为实参
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

//值作为实参
template<typename T, int max>
void func1(const T& var){
    T temp = var + max;
    std::cout << temp << std::endl;
}

template<int max, typename T>
void func2(const T& var){
    T temp = var + max;
    std::cout << temp << std::endl;
}

//字符串字面值常量不能作为模板实参
template<typename T, char* label>
void func3(const T& var){
    std::cout << var << " " << label << std::endl;
}

template <typename T>
void func4(T t1, T t2){
    std::cout << t1 + t2 << std::endl;
}

int main(){
    f(7);   //推断类型int
    f<double>(7.0);   //显示指定类型

    std::vector<int> vec{1,2,3};
    //int i = get<std::vector<int> >(vec, 1); //不能推断模版参数T,因为函数返回值的类型不能推断
    int i = get2<int>(vec, 1);
    std::cout << i << std::endl;

    func1<int, 8>(7);

    func2<8>(7);

    func4(4,5);

    //func4(1.2, 7);   // 类型不匹配

    //func3<std::string, "world">("hello"); //字符串字面值常量不能作为模板实参

    /*char str[] = "world";
    func3<std::string, str>("hello");*/
}