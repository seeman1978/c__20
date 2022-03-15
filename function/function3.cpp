#include <vector>
#include <iostream>
#include <algorithm>
#include <memory>

/**
* @file
* @brief
* @details
* @author		qiangwang
* @date		    2022/3/11
* @par Copyright(c): 	2022 mega. All rights reserved.
*/
template<class T>
class my_operator{
public:
    explicit my_operator(const T& t) : cmp_value_{t}{

    }
    virtual bool operator()(const T& a_value) = 0;

protected:
    T cmp_value_;
};

template<class T>
class my_operator_equal : public my_operator<T>{
public:
    explicit my_operator_equal(const T& t) : my_operator<T>(t) {

    }
    bool operator()(const T& a_value) override{
        if (my_operator<T>::cmp_value_ == a_value){
            return true;
        }
        else{
            return false;
        }
    };
};

template<class T>
class my_operator_less : public my_operator<T>{
public:
    explicit my_operator_less(const T& t) : my_operator<T>(t) {

    }
    bool operator()(const T& a_value) override{
        if (a_value < my_operator<T>::cmp_value_){
            return true;
        }
        else{
            return false;
        }
    };
};

template<class T>
class my_operator_agent{
public:
    explicit my_operator_agent(my_operator<T>* p):p_{p}{

    }
    virtual bool operator()(const T& a_value){
        return p_->operator()(a_value);
    };

protected:
    my_operator<T>* p_;
};

int main(){
    std::vector<int> v;
    for (int i = 0; i < 10; ++i){
        v.push_back(i);
    }
    std::shared_ptr<my_operator<int>> a_less = std::make_shared<my_operator_less<int>>(2);
    std::shared_ptr<my_operator<int>> a_equal = std::make_shared<my_operator_equal<int>>(7);
    std::cout << std::count_if(v.begin(), v.end(), my_operator_agent<int>(a_less.get())) << std::endl;
    std::cout << std::count_if(v.begin(), v.end(), my_operator_agent<int>(a_equal.get())) << std::endl;
}