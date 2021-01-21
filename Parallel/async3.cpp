//
// Created by 王强 on 2021/1/21.
//

#include <random>
#include <thread>
#include <iostream>
#include <future>

void doSomething(char c){
    std::default_random_engine dre(c);
    std::uniform_int_distribution<int> id(10, 1000);
    for (int i = 0; i < 10; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(id(dre)));
        std::cout.put(c).flush();
    }
}


int main(){
    using namespace std;
    cout << "starting 2 operations asynchronously" << '\n';

    auto f1 = async([](){doSomething('.');});
    auto f2 = async([](){doSomething('+');});

    //if at least one of the background tasks is running
    if (f1.wait_for(chrono::seconds(0)) != future_status::deferred || f2.wait_for(chrono::seconds(0)) != future_status::deferred){
        //poll until at least one of the loops finished
        while (f1.wait_for(chrono::seconds(0)) != future_status::ready && f2.wait_for(chrono::seconds(0)) != future_status::ready){
            this_thread::yield();   //hint to reschedule to the next thread
        }
    }
    cout.put('\n').flush();

    try{
        f1.get();
        f2.get();
    }
    catch (const std::exception& e){
        cout << "exception: " << e.what() << '\n';
    }
    cout << "\nDone!!" << endl;
}
