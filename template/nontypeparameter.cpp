//
// Created by 王强 on 2020/12/4.
//

#include <cstring>
#include <iostream>
template<unsigned N, unsigned M>
int compare(const char (&p1)[N], const char (&p2)[M]){
    return std::strncmp(p1, p2, N<=M?N:M);
}

template<unsigned N, unsigned M>
char * copychar(char (&pDst)[N], const char (&pSrc)[M]){
    return std::strncpy(pDst, pSrc, N<=M?N-1:M-1);
}

int main(){
    std::cout << compare("ha", "wool");
    std::cout << '\n';
    char charDst[3];
    std::cout << copychar(charDst, "world");
}