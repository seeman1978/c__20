//
// Created by 王强 on 2020/10/4.
//

class V{
public:
    V(int i){
        m_i = i;
    }

private:
    int m_i;
};

class A{
public:
    A(){};
};

class B: public virtual V, public virtual A{
public:
    B(int i):V{i}{

    }
};

class C: public virtual V{
public:
    C(int i):V{i}{

    }
};

int main(){
    C c(5);
}