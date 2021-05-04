//
// Created by wq on 2021/5/4.
//
#include <vector>
#include <c++/v1/iostream>

//如果v[i]%m == 0，则输出v[i]到输出流
void print_modulo(const std::vector<int>& v, int m){
    class Modulo_Print{
    public:
        Modulo_Print(int mm):m_m{mm}{}; //捕获
        void operator()(int x) const{
            if (x%m_m == 0){
                std::cout << x << '\n';
            }
        }
    private:
        int m_m;
    };
    for_each(v.begin(), v.end(), Modulo_Print{m});
}

//如果v[i]%m == 0，则输出v[i]到输出流
void print_modulo_lambda(const std::vector<int>& v, int m) {
    for_each(v.begin(), v.end(), [m](int x){if (x%m == 0){std::cout << x << '\n';}});
}

void print_modulo_for(const std::vector<int>& v, int m){
    for (auto x:v) {
        if (x%m == 0){
            std::cout << x << '\n';
        }
    }
}

int main(){
    std::vector<int> v{1,2,3,4,5,6,7,8,9};
    print_modulo(v, 3);
    print_modulo_lambda(v, 3);
    print_modulo_for(v, 3);
}