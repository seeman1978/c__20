/**
* @file
* @brief
* @details
* @author		qiangwang
* @date		    2021/11/5
* @par Copyright(c): 	2021 mega. All rights reserved.
*/

template <class Func>
void call(Func f)
{
    f();
}

void func() noexcept { }

int main()
{
    call(func);
}
