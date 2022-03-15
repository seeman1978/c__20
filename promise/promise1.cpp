#include <future>
#include <map>

/**
* @file
* @brief
* @details
* @author		qiangwang
* @date		    2022/3/11
* @par Copyright(c): 	2022 mega. All rights reserved.
*/
void consume(){

    p.set_value();
}


void produce(int i){
    std::promise<std::string> p;

    std::thread t{consume, p};



}





int main(){


}