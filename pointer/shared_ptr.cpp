//
// Created by zhaoyue on 2020/11/24.
//

#include <iostream>
struct connection{
    connection()=default;
    ~connection(){
        std::cout << "destroy connection";
    }
    std::string strConn;
};

void end_connection(connection *p){
    std::cout << "disconnection\n";
    delete p;   //如果不主动调用delete去释放内存，会造成内存泄露。deleter不会帮我们主动的释放内存。
}

int main(){
    //std::make_shared does not allow a custom deleter.
    std::shared_ptr<connection> pConn {new connection, end_connection};
}