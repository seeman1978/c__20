//
// Created by 王强 on 2021/1/21.
//

#include <future>
#include <iostream>
#include <sstream>

void dosomething(std::promise<std::string>& p){
    using namespace std;
    try {
        cout << "read char ('x' for exception): " ;
        char c = cin.get();
        if (c == 'x'){
            throw runtime_error(string("char ") + c + " read");
        }
        ostringstream o;
        o << "char " << c << " processed";
        string s = o.str();
        p.set_value(move(s));
    }
    catch (...) {
        p.set_exception(current_exception());
    }
}

int main(){
    using namespace std;
    try {
        promise<string> p;
        thread t(dosomething, ref(p));

        future<string> f(p.get_future());

        cout << "result: " << f.get() << '\n';
    }
    catch (const std::exception& e){
        std::cerr << "exception: " << e.what() << '\n';
    }
    catch (...) {
        cerr << "exception: " << '\n';
    }
}