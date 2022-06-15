//
// Created by wq on 22-6-15.
//
#include <string>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <array>
#include <vector>

int main()
{
    uint32_t max_number_of_block_length{0x12340000};
    std::vector<uint8_t> config_buf(4);
    config_buf[0] = (max_number_of_block_length >> 24) & 0xFF;
    config_buf[1] = (max_number_of_block_length >> 16) & 0xFF;
    config_buf[2] = (max_number_of_block_length >>  8) & 0xFF;
    config_buf[3] = (max_number_of_block_length >>  0) & 0xFF;
    std::cout << config_buf.size() << std::endl;
    for(uint32_t i : config_buf){
        std::cout << i << std::endl;
    }

    std::vector<std::uint8_t> v;

    std::uint32_t i=0x11223344;

    v.push_back( (i >> 24) & 0xFF);
    v.push_back( (i >> 16) & 0xFF);
    v.push_back( (i >>  8) & 0xFF);
    v.push_back( (i >>  0) & 0xFF);

    for(uint32_t c : v)
    {
        std::cout << std::hex << c << " ";
    }
}