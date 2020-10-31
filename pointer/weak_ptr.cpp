//
// Created by 王强 on 2020/10/28.
//

#include <memory>
#include <iostream>
std::weak_ptr<int> gw;

struct B;

struct A{
    A()=default;
    A(B* pB){
        m_pB = pB;
    }
    ~A(){
        std::cout << "destroy A" << std::endl;
    }
    B* m_pB;
};

struct B{
    B()=default;
    B(A* pA){
        m_pA = pA;
    }
    ~B(){
        std::cout << "destroy B" << std::endl;
    }
    A* m_pA;
};

void observer(){
    using std::cout;
    cout << "use_count == " << gw.use_count() << ": ";
    if (auto spt = gw.lock()){// Has to be copied into a shared_ptr before usage
        cout << *spt << '\n';
    }
    else{
        cout  << "gw is expired\n";
    }
}

int main(){
    {
        auto sp = std::make_shared<int>(42);
        gw = sp;
        observer();
        observer();
    }
    observer();

    {
        std::shared_ptr<A> pA = std::make_shared<A>();
        std::shared_ptr<B> pB = std::make_shared<B>(pA.get());
        std::shared_ptr<A> pA2 = std::make_shared<A>(pB.get());
    }
}