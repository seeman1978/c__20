//
// Created by wq on 2020/10/23.
//

#include <map>
#include <functional>
#include <chrono>
#include <iostream>
#include <iomanip>

const int nof_operations = 100500;

int map_emplace(){
    std::map<int, char> m;
    for (int i=0; i<nof_operations; ++i){
        m.emplace(i, 'a');
    }
    return m.size();
}

int map_emplace_hint(){
    std::map<int, char> m;
    auto it = m.begin();
    for (int i=0; i<nof_operations; ++i){
        m.emplace_hint(it, i, 'b');
        it = m.end();
    }
    return m.size();
}

int map_emplace_hint_wrong(){
    std::map<int , char> m;
    auto it = m.begin();
    for (int i=nof_operations; i>0; --i){
        m.emplace_hint(it, i, 'c');
        it = m.end();
    }
    return m.size();
}

int map_emplace_hint_corrected(){
    std::map<int, char> m;
    auto it = m.begin();
    for(int i=nof_operations; i>0; --i){
        m.emplace_hint(it, i, 'd');
        it = m.begin();
    }
    return m.size();
}

int map_emplace_hint_closest(){
    std::map<int ,char> m;
    auto it = m.begin();
    for(int i=0; i<nof_operations; ++i){
        it = m.emplace_hint(it, i, 'e');
    }
    return m.size();
}

void timeit(std::function<int()> map_test, const std::string& what=""){
    auto start = std::chrono::system_clock::now();
    int mapsize = map_test();
    auto stop = std::chrono::system_clock::now();
    std::chrono::duration<double, std::milli> t = stop - start;
    if (what.size() > 0 && mapsize > 0){
        std::cout << std::fixed << std::setprecision(2) << std::setw(5) << t.count() << " ms for " << what << '\n';
    }
}

int main(){
    timeit(map_emplace); // stack warmup
    timeit(map_emplace, "plain emplace");
    timeit(map_emplace_hint, "emplace with correct hint");
    timeit(map_emplace_hint_wrong, "emplace with wrong hint");
    timeit(map_emplace_hint_corrected, "corrected emplace");
    timeit(map_emplace_hint_closest, "emplace using returned iterator");
}