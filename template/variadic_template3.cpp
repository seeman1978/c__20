//
// Created by wq on 2021/6/22.
//

template<typename I, template<typename> class... B>
struct Container{};

template<typename I, template<typename> class A, template<typename> class... B>
struct Container<I, A, B...>{
    A<I> a;
    Container<I, B...> b;
};

template<typename I>
struct Container<I>{};