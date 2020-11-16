//
// Created by zhaoyue on 2020/11/16.
//

#include <vector>
#include <algorithm>
#include <future>
#include <iostream>
#include <chrono>

int find_rec(std::vector<int>& vr, int first, int last, int val){
    std::vector<int>::iterator p = std::find(vr.begin()+first, vr.begin()+last, val);
    if (p == vr.begin()+last){
        return -1;  //not found
    }
    else{
        return *p;
    }
}

std::vector<int> find_all_rec(std::vector<int>& vr, int first, int last, int val){
    std::vector<int> res;
    for (int i = first; i != last; ++i) {
        if (vr[i] == val){
            res.push_back(vr[i]);
        }
    }
    return res;
}

const int grain = 50000;

int parallel_find(std::vector<int> &vr, int val){
    assert(vr.size()%grain == 0);
    std::vector<std::future<int>> res;

    for (int i = 0; i != vr.size(); i+=grain) {
        res.push_back(std::async(find_rec, std::ref(vr), i, i+grain, val));
    }

    for (int j = 0; j != vr.size() ; ++j) {
        auto p = res[j].get();
        if (p != -1){
            return p;
        }
    }
    return -1;
}

template<typename T>
int wait_for_any(std::vector<std::future<T>>& vf, std::chrono::steady_clock::duration d){
    while(true){
        for (int i=0; i != vf.size(); ++i){
            if (!vf[i].valid()){
                continue;
            }
            switch (vf[i].wait_for(std::chrono::seconds{0})) {
                case std::future_status::ready:
                    return i;
                case std::future_status::timeout:
                    break;
                case std::future_status::deferred:
                    throw std::runtime_error("wait for all: deferred future");
            }
        }
        std::this_thread::sleep_for(d);
    }
}

int parallel_find_any(std::vector<int> &vr, int val){
    assert(vr.size()%grain == 0);
    std::vector<std::future<int>> res;

    for (int i = 0; i != vr.size(); i+=grain) {
        res.push_back(std::async(find_rec, std::ref(vr), i, i+grain, val));
    }

    for (int count = res.size(); count != 0; --count) {
        int i = wait_for_any(res, std::chrono::microseconds{10});
        auto p = res[i].get();
        if (p != -1){
            return p;
        }
    }
    return -1;
}

template<typename T>
std::vector<T> wait_for_all(std::vector<std::future<T>>& vf){
    std::vector<T> res;
    for (auto &fu : vf) {
        res.push_back(fu.get());
    }
    return res;
}

std::vector<int> parallel_find_all(std::vector<int> &vr, int val){
    assert(vr.size()%grain == 0);
    std::vector<std::future<std::vector<int>>> res;

    for (int i = 0; i != vr.size(); i+=grain) {
        res.push_back(std::async(find_all_rec, std::ref(vr), i, i+grain, val));
    }

    std::vector<std::vector<int>> r2 = wait_for_all(res);
    std::vector<int> r;
    for (auto& x : r2){
        for (auto p : x){
            r.push_back(p);
        }
    }
}

int main(){
    std::vector<int> goods;
    for (int i = 0; i < 100000; ++i) {
        goods.push_back(i);
    }

    assert(goods.size()%grain == 0);
    int val = parallel_find(goods, 999);
    std::cout << "record is " << val << '\n';

    val = parallel_find_any(goods, 999999999);
    std::cout << "record is " << val;
}