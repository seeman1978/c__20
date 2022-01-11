#include <optional>
#include <iostream>

/**
* @file
* @brief
* @details
* @author		qiangwang
* @date		    2022/1/11
* @par Copyright(c): 	2022 mega. All rights reserved.
*/

int main(){
    /*
        The object does not contain a value in the following conditions:

        The object is default-initialized.
        The object is initialized with/assigned from a value of type std::nullopt_t or an optional object that does not contain a value.
        The member function reset() is called.
     * */
    std::optional<int> o{};

    if (o){
        o = 10;
        std::cout << o.value(); //no output
    }
}