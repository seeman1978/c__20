//
// Created by 王强 on 2021/1/5.
//

#include <regex>
#include <iostream>

int main(){
    using namespace std;
    string pat1{R"(\\.index\{([^}]*)\})"};  //first capture group
    string pat2{R"(\\.index\{(.*)\}\{(.*)\})"};
    regex pat{pat1+"\n"+pat2, regex_constants::egrep|regex_constants::icase};

    string data{istreambuf_iterator<char>(cin), istreambuf_iterator<char>()};   //command+d,结束cin等待
    //search and print matching index entries:
    smatch m;
    auto pos = data.cbegin();
    auto end = data.cend();
    for ( ; regex_search(pos, end, m, pat); pos=m.suffix().first){
        cout << "match: " << m.str() << endl;
        cout << "  val: " << m.str(1) + m.str(2) << endl;
        cout << "  see: " << m.str(3) << endl;
    }
}