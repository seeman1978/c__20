//
// Created by 王强 on 2020/9iiii/22.
//
namespace X{
    int i=1,j=2,k=3;
}

int k = 9 ;
void f1()
{
    //int i = 8;
    using namespace X;
    i++;
    ::k++;
}

int main()
{
    f1();
}
