//
// Created by zhaoyue on 2020/11/24.
//

//
// Created by zhaoyue on 2020/11/24.
//

#include <iostream>
struct connection{
    connection()=default;
    connection(int i):m_i{i}{

    }
    ~connection(){
        std::cout << m_i << " destroy connection\n";
    }
    std::string strConn;
    int m_i;
};

void end_connection(connection *p){
    std::cout << p->m_i << " disconnection\n";
    delete p;   //如果不主动调用delete去释放内存，会造成内存泄露。deleter不会帮我们主动的释放内存。
}

int main(){
    //std::make_shared does not allow a custom deleter.
    std::unique_ptr<connection, decltype(end_connection)*> pConn {new connection(1), end_connection};

    std::unique_ptr<connection> pConn2 = std::make_unique<connection>(2);
}