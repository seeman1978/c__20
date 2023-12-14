//
// Created by zhaoyue on 2020/11/24.
//

//
// Created by zhaoyue on 2020/11/24.
//

#include <iostream>
#include <memory>

struct connection{
    connection()=default;
    explicit connection(int i):m_i{i}{

    }
    ~connection(){
        std::cout << m_i << " destroy connection\n";
    }
    void print() const{
        std::cout << m_i << " \n";
    }
    std::string strConn;
    int m_i{};
};

void end_connection(connection *p){
    std::cout << p->m_i << " disconnection\n";
    delete p;   //如果不主动调用delete去释放内存，会造成内存泄露。deleter不会帮我们主动的释放内存。
}

int main(){
    //std::make_unique does not allow a custom deleter.
    std::unique_ptr<connection, decltype(end_connection)*> pConn {new connection(1), end_connection};

    std::unique_ptr<connection> pConn2 = std::make_unique<connection>(2);
    std::unique_ptr<connection> pConn3 = std::move(pConn2);
    pConn3->print();
    if (pConn2 != nullptr){
        pConn2->print();
    }
}