//
// Created by 王强 on 2020/10/23.
//
#include <string>
#include <set>
#include <iostream>

struct Record{
    std::string label;
    int value;
};

bool operator<(const Record& a, const Record& b){
    return a.label < b.label && a.value<b.value;
}

int main(){
    using namespace std;
    set<Record> mr{{"a", 22},{"a", 11}, {"b", 1}};
    int n = mr.size();
    for (const auto& p : mr){
        cout << '{' << p.label << ':' << p.value << '}';
    }
    cout << '\n';
}

