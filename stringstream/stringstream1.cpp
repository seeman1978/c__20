/**
* @file
* @brief
* @details
* @author		qiangwang
* @date		    2021/10/28
* @par Copyright(c): 	2021 mega. All rights reserved.
*/

#include <iostream>
#include <sstream>
int main()
{
    // default constructor (input/output stream)
    std::stringstream buf1;
    buf1 << 7;
    int n = 0;
    buf1 >> n;
    std::cout << "buf1 = " << buf1.str() << " n = " << n << '\n';

    std::stringstream buf3;
    uint16_t instanceId{999};
    buf3 << instanceId;
    std::cout << "buf3 = " << buf3.str() << " instanceId = " << instanceId << '\n';

    // input stream
    std::istringstream inbuf("-10");
    inbuf >> n;
    std::cout << "n = " << n << '\n';

    // output stream in append mode (C++11)
    std::ostringstream buf2("test", std::ios_base::ate);
    buf2 << '1';
    std::cout << buf2.str() << '\n';
}