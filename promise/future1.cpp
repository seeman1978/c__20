#include <future>
#include <iostream>

/**
* @file
* @brief
* @details
* @author		qiangwang
* @date		    2021/12/22
* @par Copyright(c): 	2021 mega. All rights reserved.
*/

std::future<std::string> method() {
    std::promise<std::string> pr;
    std::future<std::string> ft = pr.get_future();

    std::thread t(
            [](std::promise<std::string> p)
            {
                p.set_value("z");
                std::cout << "b\n";
            },
            std::move(pr)
    );
    t.detach();

    return std::move(ft);
}

int main(){
    auto r = method();
    std::cout << "a\n";
    r.get();
    std::cout << "c\n";
}