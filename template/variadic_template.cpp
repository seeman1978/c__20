//
// Created by 王强 on 2021/6/21.
// 变长模版 ： 由模版参数包和函数参数包，两部分组成

template <typename ... Elements>
class MyTuple;
template<typename Head, typename ... Tail>
class MyTuple<Head, Tail... >:private MyTuple<Tail... >{
    Head head;
};
template<> class MyTuple<>{};