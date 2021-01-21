//
// Created by 王强 on 2021/1/21.
//

#include <random>
#include <thread>
#include <iostream>

void doSomething(int num, char c){
    using namespace std;
    try{
        default_random_engine dre(42*c);
        uniform_int_distribution<int> id(10, 1000);
        for (int i = 0; i < num; ++i) {
            this_thread::sleep_for(chrono::milliseconds(id(dre)));
            cout.put(c).flush();
        }
    }
    catch (const exception& e){
        cerr << "thread exception (thread " << this_thread::get_id() << "): " << e.what() << '\n';
    }
    catch (...) {
        cerr << "thread unknown exception (thread " << this_thread::get_id() << ")" << '\n';
    }
}

int main(){
    using namespace std;
    try {
        thread t1(doSomething, 5, '.');
        cout << "- started fg thread " << t1.get_id() << '\n';

        for (int i = 0; i < 5; ++i) {
            thread t(doSomething, 10, 'a'+i);
            cout << "- detach started bg thread " << t.get_id() << '\n';
            t.detach(); //detach thread into the background
        }
        cin.get();
        cout << "- join fg thread " << t1.get_id() << '\n';
        t1.join(); //wait for t1 to finish
    }
    catch (const exception& e){
        cerr << "exception: " << e.what() << '\n';
    }
}