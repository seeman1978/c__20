/**
* @file
* @brief
* @details
* @author		qiangwang
* @date		    2022/2/18
* @par Copyright(c): 	2022 mega. All rights reserved.
*/

// preprocessor_token_pasting.cpp
#include <cstdio>
#define paster( n, m ) printf( "token" #n " = %d", token##n##m##j )
int token92j = 9;

int main()
{
    paster(9, 2);
}