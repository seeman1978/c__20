//
// Created by 王强 on 2021/1/14.
//

#include <iostream>
#include <fstream>
#include <memory>

void redirect(std::ostream& strm){
    using namespace std;
    auto del = [&](streambuf* p){
        strm.rdbuf(p);
    };
    unique_ptr<streambuf, decltype(del)> origBuffer(strm.rdbuf(), del);
    ofstream file("redirect.txt");
    strm.rdbuf(file.rdbuf());

    file << "one row for the file" << endl;
    strm << "one row for the stream" << endl;
}

int main(){
    std::cout << "the first row" << std::endl;
    redirect(std::cout);
    std::cout << "the last row" << std::endl;
}