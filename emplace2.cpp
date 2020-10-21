//
// Created by 王强 on 2020/10/21.
//

#include <string>
#include <iostream>
#include <vector>

struct A{
    explicit A(std::string str):s(std::move(str)){
        std::cout << "  constructed:" << s << "\n";
    }
    A(const A& o) : s(o.s){
        std::cout << "  copy constructed:" << s << "\n";
    }
    A(A&& o):s(std::move(o.s)){
        std::cout << "  move constructed:" << s << "\n";
    }
    A& operator=(const A& o){
        s = o.s;
        std::cout << "  copy assigned:" << s << "\n";
        return *this;
    }
    A& operator=(A&& o){
        s = std::move(o.s);
        std::cout << "  move assigned:" << s << "\n";
        return *this;
    }
    std::string s;
};

int main(){
    std::vector<A> container;
    // reserve enough place so vector does not have to resize
    container.reserve(10);

    std::cout << "construct 2 times A:\n";
    A two{"two"};
    A three {"three"};
    std::cout << "emplace:\n";
    container.emplace(container.end(), "one");  //The element is constructed through std::allocator_traits::construct, which typically uses placement-new to construct the element .即使构造函数被声明为explicit。

    std::cout << "emplace with A&:\n";
    container.emplace(container.end(), two);

    std::cout << "emplace with A&&:\n";
    container.emplace(container.end(), std::move(three));

    std::cout << "content:\n";
    for(const auto& obj : container){
        std::cout << ' ' << obj.s;
    }
    std::cout << '\n';
}