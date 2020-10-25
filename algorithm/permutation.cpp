//
// Created by wq on 2020/10/25.
//

#include <string>
#include <iostream>

int main()
{
    {
        std::string s = "aba";
        std::sort(s.begin(), s.end());
        do {
            std::cout << s << '\n';
        } while(std::next_permutation(s.begin(), s.end()));
    }
    {
        std::string s = "aba";
        std::sort(s.begin(), s.end());
        do {
            std::cout << s << '\n';
        } while(std::prev_permutation(s.begin(), s.end()));
    }

}