//
// Created by wq on 23-12-19.
//

#include <functional>
#include <future>
#include <iostream>
#include <utility>
#include <unistd.h>

using callback = std::function<void()>;

class A{
public:
    explicit A(std::string str){
        str_ = std::move(str);
    }
    void f1(){
        std::cout << str_ << " A::f1\n";
    }
private:
    std::string str_;
};

class B{
public:
    void set_callback(callback f_cb){
        f_cb_ = std::move(f_cb);
    }

    void invoke(){
        if (f_cb_ != nullptr){
            f_cb_();
        }
    }
private:
    callback f_cb_{};
};

class C : public std::enable_shared_from_this<C>{
public:
    explicit C(std::string str){
        str_ = std::move(str);
    }
    void f1(){
        std::cout << str_ << " C::f1\n";
    }
private:
    std::string str_;
};

int main(){
    {
        std::shared_ptr<A> pA = std::make_shared<A>("Hello");

        std::shared_ptr<B> pB = std::make_shared<B>();

        pB->set_callback([&pA](){
            pA->f1();
        });
        //pA.reset();
        pB->invoke();
    }

    {
        std::shared_ptr<C> pC = std::make_shared<C>("Hello");

        std::shared_ptr<B> pB = std::make_shared<B>();

        std::weak_ptr<C> self = pC->shared_from_this();

        pB->set_callback([&pC, self](){
            if (self.lock()){
                pC->f1();
            }
        });

        std::future<void> f1 = std::async(std::launch::async, [&pB]{
            pB->invoke();
        });

        pC.reset();
        f1.get();
    }
}