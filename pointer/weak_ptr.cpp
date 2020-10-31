//
// Created by 王强 on 2020/10/28.
//

#include <memory>
#include <iostream>
std::weak_ptr<int> gw;

struct B;

struct A{
    A()=default;
    explicit A(B* pB){
        m_pB = pB;
    }
    ~A(){
        std::cout << "destroy A" << std::endl;
    }
    B* m_pB;
};

struct B{
    B()=default;
    explicit B(A* pA){
        m_pA = pA;
    }
    ~B(){
        std::cout << "destroy B" << std::endl;
    }
    A* m_pA;
};

struct C{
    C()=default;
    ~C(){
        std::cout << "destroy C" << std::endl;
    }
    std::shared_ptr<C> m_pC;
};

struct D{
    D()=default;
    explicit D(std::shared_ptr<A> pA){
        m_pA = pA;
    }
    ~D(){
        std::cout << "destroy D" << std::endl;
    }
    std::shared_ptr<A> m_pA;
};

struct E{
    E()=default;
    ~E(){
        std::cout << "destroy E" << std::endl;
    }
    std::weak_ptr<E> m_pE;
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

    {//ok,不会引发内存泄漏
        std::shared_ptr<A> pA = std::make_shared<A>();
        std::shared_ptr<B> pB = std::make_shared<B>(pA.get());
        std::shared_ptr<A> pA2 = std::make_shared<A>(pB.get());
    }

    {//C doesn't be destroyed.
        std::shared_ptr<C> pC1 = std::make_shared<C>();
        std::shared_ptr<C> pC2 = std::make_shared<C>();

        pC1->m_pC = pC2;
        pC2->m_pC = pC1;
    }

    {
        std::shared_ptr<A> pA = std::make_shared<A>();
        std::shared_ptr<D> pD = std::make_shared<D>(pA);
    }

    {//E is destroyed.
        std::shared_ptr<E> pE1 = std::make_shared<E>();
        std::shared_ptr<E> pE2 = std::make_shared<E>();

        pE1->m_pE = pE2;
        pE2->m_pE = pE1;
    }
}