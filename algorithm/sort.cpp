//
// Created by zhaoyue on 2020/10/26.
//

#include <array>
#include <iostream>
#include <vector>

template<typename T>
void print(const T& s){
    for(auto a : s){
        std::cout << a << ' ';
    }
    std::cout << '\n';
}

struct Employee{
    int age;
    std::string name;  // Does not participate in comparisons
    };

bool operator<(const Employee& lhs, const Employee& rhs){
    return lhs.age < rhs.age;
}

int main(){
    using namespace std;
    {
        array<int, 10> s {5, 7, 4, 2, 8, 6, 1, 9, 0, 3};
        sort(s.begin(), s.end());
        print(s);

        sort(s.begin(), s.end(), greater<>());  //greater<>()代替greater<int>()，可以放置类型不匹配，greater<>()的类型由编译器自动推导。
        print(s);

        struct {
            bool operator()(int a, int b) const{
                return a<b;
            }
        } customLess;
        sort(s.begin(), s.end(), customLess);
        print(s);

        sort(s.begin(), s.end(),[](int a, int b){return a>b;});
        print(s);
    }
    {
        vector<Employee> v = {
                {108, "Zaphod"},
                {32, "Arthur"},
                {108, "Ford"},
        };
        stable_sort(v.begin(), v.end());
        for (const auto& e : v){
            cout << e.age << ',' << e.name << '\n';
        }
    }
    {
        std::array<int, 10> s{5, 7, 4, 2, 8, 6, 1, 9, 0, 3};

        std::partial_sort(s.begin(), s.begin() + 3, s.end());
        for (int a : s) {
            std::cout << a << " ";
        }
        cout << '\n';
    }
    {
        std::vector<int> v{5, 6, 4, 3, 2, 6, 7, 9, 3};

        std::nth_element(v.begin(), v.begin() + v.size()/2, v.end());
        std::cout << "The median is " << v[v.size()/2] << '\n';

        std::nth_element(v.begin(), v.begin()+1, v.end(), std::greater<>());
        std::cout << "The second largest element is " << v[1] << '\n';
    }
}