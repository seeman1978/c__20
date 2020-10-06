//
// Created by 王强 on 2020/10/4.
//

class A{

};

class B{

};

int main(){
    int *pI = new int{19};

    A* pA = new A;

    //pA = dynamic_cast<A*>(pI);    //无法编译，编译器知道类型不匹配

    B* pB = new B;

    //pA = dynamic_cast<A*>(pB);  //无法编译，编译器知道类型不匹配
}