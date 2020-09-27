//
// Created by zhaoyue on 2020/9/27.
//

struct X{
    int m_i;
    X()=default;
    X(int i){
        m_i = i;
    }
};

struct S{
    int m_j;
    X m_x;

};

int main(){
    S s{6};
    S s2{6, 7}; //逐成员初始化，按照声明的顺序
}
