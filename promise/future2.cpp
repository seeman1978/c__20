/**
* @file
* @brief
* @details
* @author		qiangwang
* @date		    2021/12/22
* @par Copyright(c): 	2021 mega. All rights reserved.
*/
#include <string>
#include <future>
#include <iostream>
#include <thread>

using namespace std;
string s = "not written";

void write(std::promise<void>&& writePromise)
{
    cout << "\nwrite()" << endl;
    this_thread::sleep_for(chrono::seconds(1));
    s = "written";
    writePromise.set_value();
}

void read(future<void>&& readFut)
{
    cout << "read(), waiting..." << flush;
    readFut.wait();
    cout << "\ns: '" << s << "'" << endl;
}

//int main()
//{
//    promise<void> writePromise;
//    future<void> writeFuture = writePromise.get_future();
//
//    thread tWrite(write, move(writePromise));
//    thread tRead(read, move(writeFuture));
//
//    tWrite.join();
//    tRead.join();
//}

int main()
{
    promise<void> writePromise;

    thread tWrite(write, move(writePromise));
    thread tRead(read, move(writePromise.get_future()));

    tWrite.join();
    tRead.join();
}